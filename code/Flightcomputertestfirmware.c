/*
This code tests the flight computer, and all of its functions, and proves capibilites liek PID. it DOES NOT have actual rocket guidence code, since that is ileagal.
A blueprint organizer has aproved, that I dont have to provide the guidence code in github. The real code DOES exist, but I cant share it.
*/

#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_BMP3XX.h>
#include "BMI270_SensorAPI.h"

// ================= PINS =================
#define SERVO_PIN 25
#define PYRO1_PIN 26
#define PYRO2_PIN 27

// ================= OBJECTS =================
Servo testServo;
Adafruit_BMP3XX bmp;

// BMI270 variables
struct bmi2_dev bmi;
struct bmi2_sens_data sensor_data;

// ================= PID =================
float targetAngle = 0.0;   // degrees
float angle = 0.0;
float gyroRate = 0.0;

float Kp = 3.0;
float Ki = 0.02;
float Kd = 0.15;

float error, lastError = 0;
float integral = 0;
float derivative;
float pidOutput;

// Timing
unsigned long lastTime;

// ================= BMI CALLBACKS =================
int8_t bmi_read(uint8_t reg, uint8_t *data, uint32_t len, void *intf_ptr) {
  Wire.beginTransmission(BMI2_I2C_PRIM_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(BMI2_I2C_PRIM_ADDR, len);
  for (uint32_t i = 0; i < len; i++) data[i] = Wire.read();
  return BMI2_OK;
}

int8_t bmi_write(uint8_t reg, const uint8_t *data, uint32_t len, void *intf_ptr) {
  Wire.beginTransmission(BMI2_I2C_PRIM_ADDR);
  Wire.write(reg);
  for (uint32_t i = 0; i < len; i++) Wire.write(data[i]);
  Wire.endTransmission();
  return BMI2_OK;
}

void bmi_delay(uint32_t ms, void *intf_ptr) {
  delay(ms);
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(PYRO1_PIN, OUTPUT);
  pinMode(PYRO2_PIN, OUTPUT);
  digitalWrite(PYRO1_PIN, LOW);
  digitalWrite(PYRO2_PIN, LOW);

  // Servo
  testServo.setPeriodHertz(50);
  testServo.attach(SERVO_PIN, 1000, 2000);

  // BMP390
  if (!bmp.begin_I2C()) {
    Serial.println("BMP390 FAIL");
    while (1);
  }

  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);

  // BMI270
  bmi.intf = BMI2_I2C_INTF;
  bmi.read = bmi_read;
  bmi.write = bmi_write;
  bmi.delay_us = bmi_delay;
  bmi.intf_ptr = NULL;

  if (bmi270_init(&bmi) != BMI2_OK) {
    Serial.println("BMI270 FAIL");
    while (1);
  }

  bmi2_sens_config config[2];
  config[0].type = BMI2_ACCEL;
  config[1].type = BMI2_GYRO;

  bmi2_set_sensor_config(config, 2, &bmi);
  bmi2_sensor_enable(BMI2_ACCEL | BMI2_GYRO, &bmi);

  lastTime = millis();

  Serial.println("SYSTEM OK");
}

// ================= LOOP =================
void loop() {
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  lastTime = now;

  // ===== IMU =====
  bmi2_get_sensor_data(&sensor_data, &bmi);

  float ax = sensor_data.acc.x / 16384.0;
  float az = sensor_data.acc.z / 16384.0;
  gyroRate = sensor_data.gyr.y * 0.061; // deg/s

  float accelAngle = atan2(ax, az) * 57.2958;

  // Complementary filter
  angle = 0.98 * (angle + gyroRate * dt) + 0.02 * accelAngle;

  // ===== PID =====
  error = targetAngle - angle;
  integral += error * dt;
  derivative = (error - lastError) / dt;
  lastError = error;

  pidOutput = Kp * error + Ki * integral + Kd * derivative;
  pidOutput = constrain(pidOutput, -30, 30);

  // Servo center = 90
  testServo.write(90 + pidOutput);

  // ===== BARO =====
  bmp.performReading();

  // ===== PYRO TEST (VERY SHORT PULSE) =====
  static unsigned long lastPyro = 0;
  if (millis() - lastPyro > 5000) {
    digitalWrite(PYRO1_PIN, HIGH);
    delay(50);
    digitalWrite(PYRO1_PIN, LOW);
    lastPyro = millis();
  }

  // ===== DEBUG =====
  Serial.print("Angle:");
  Serial.print(angle);
  Serial.print(" PID:");
  Serial.print(pidOutput);
  Serial.print(" Alt:");
  Serial.println(bmp.readAltitude(1013.25));

  delay(10);
}
