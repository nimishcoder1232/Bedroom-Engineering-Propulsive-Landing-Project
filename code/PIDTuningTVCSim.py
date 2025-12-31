'''
Nimish Nijhawan
 THis program simulates the rocket as it flies. This is made by me and is NOT vibe coded. As you can see, all the constants for physics are stored in variables, like the MMOI.
 Then it simulates teh flight charactheristics and prints them out. This allows you to tune the PID variables. 
 '''

from simple_pid import PID 
import math
import time
from random import randint

pid = PID(0.12, 0.04, 0.04, setpoint=0)
pid.output_limits = (-100, 100)

orientation_deg = 45
loop_time = 0.01  # seconds
sidethrust = 0 # newtons 
calculated_thrust = 15 # newtons
acelerometer_noise = 0.5  # newtons
mmoi = 0.03  # kg m^2
tvc_com = 30 # cm 
max_gimbal_angle = 5  
gimbal_slop = 0.2  
oriention_slop = 0.2
prevtime = time.perf_counter()  # seconds with high resolution
roational_velocity = 0.0

# <<< ADDED (TVC STATE)
tvc_delay_s = 0.05
tvc_rate_dps = 36
current_gimbal_angle = 0.0
command_issue_time = None




while True:
    
    currenttime = time.perf_counter()  # seconds with high resolution
    dt = (currenttime - prevtime)  # seconds
    prevtime = currenttime

    recordedorientation = orientation_deg
    recordedorientation += randint(-1, 1) * oriention_slop

    sidethrust = pid(recordedorientation, dt)

    angle_command = math.atan2(sidethrust, calculated_thrust)
    angle_command = math.degrees(angle_command)
    angle_command += randint(-1, 1) * gimbal_slop

    # limit command angle to max gimbal angle
    if angle_command > max_gimbal_angle:
        angle_command = max_gimbal_angle
    elif angle_command < -max_gimbal_angle:
        angle_command = -max_gimbal_angle

    # <<< REPLACED: command → real servo
    
    realthrust = calculated_thrust + randint(-1, 1) * acelerometer_noise

    # <<< REPLACED: use REAL gimbal angled
    realthrust = realthrust * math.cos(math.radians(current_gimbal_angle))

    torqu = realthrust * (tvc_com / 100.0) # tis is in newton meters :D

    angular_acceleration = math.degrees(torqu / mmoi)  #degs per sec squared

    roational_velocity += angular_acceleration * dt  # degs per sec

    orientation_deg += roational_velocity * dt

    print(f"Orientation: {orientation_deg:.2f} deg, Sidethrust: {actual_sidethrust:.2f} N")
    time.sleep(loop_time)
