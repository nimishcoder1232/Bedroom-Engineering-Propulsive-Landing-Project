# Bedroom-Engineering-Propulsive-Landing-Project
This repo has everything that I made for my rocket that can propulsive landing, while still being under ITAR restrictions. 

For this project, I will design a rocket that can launch and then do a propulsive landing. In order to meet this challenge, I will have to make a new custom ESP32-based flight computer. I will have to make a quaternion orientation calculation system, I will have to design a control loop, and I will have to make a simulator in Python, without vibe coding, because it is too complicated. The simulator will simulate the rocket’s flight to help tune the control loop and the propulsive landing.

I did this project for a few reasons. The first reason I did it, is because in gneral, this is my passion. I love both engineering and rockets, so this is satisfactory for me. This isant a project for me, this project is more, who I am. I also made this project to learn from it. Throughout this project, I have learned sooo much, PCB design, CAD, Programign in many languages, soldering. And SO much more. Every time I sit down to do one of these projects, I end up learning so much. That is the second reason I work on these projects, To learn From them. 

Notes:
I am 3d printing everything myself, I DONT need reinbursment
Anything thats NOT in the cad, is provided by me. (THe engines and the big DC motor
are in the cad, but I am providing those) 
This BOM only has the stuff, I CANT provide myself. 

Project Link: https://blueprint.hackclub.com/projects/7459

Full Rocket: 

<img width="488" height="703" alt="image" src="https://github.com/user-attachments/assets/3a1ad29f-37d5-4d32-89af-6cb436f460de" />

PCB schematic: 

<img width="812" height="520" alt="image" src="https://github.com/user-attachments/assets/d7aeefdc-e3cc-4290-a1af-7418a53d04ce" />

PCB Routing: 

<img width="385" height="640" alt="image" src="https://github.com/user-attachments/assets/d7426274-cea3-4ea4-95d7-992c20380233" />

PCB Preview: 

<img width="493" height="763" alt="image" src="https://github.com/user-attachments/assets/e846b921-9f72-4703-9e44-543c6d77e6a9" />

|Item Name                                                              |Link                                                                                          |Quanity|Cost  USD|Notes                                                                             |
|-----------------------------------------------------------------------|----------------------------------------------------------------------------------------------|-------|---------|----------------------------------------------------------------------------------|
|Carbon Fiber Rod 400mm 5 pack                                          |https://www.amazon.com/FOCMKEAS-Carbon-4mm-400mm-Airplane/dp/B0DGF1CMPT/ref                   |2      |20       |                                                                                  |
|drv8833 motor controler 2 pack                                         |https://www.amazon.com/KOOBOOK-DRV8833-Module-Bridge-Controller/dp/B07S7Z8CFL/ref             |1      |6        |Two per pack, only need one. but cheapest listing I could find                    |
|ES08MA &#124;&#124; servos 2 poack                                               |https://www.amazon.com/Wishiot-ES08MA-2-0kg-cm-Rotation-Lightweight/dp/B0FQV6KFTC/ref         |1      |24       |                                                                                  |
|Solder Paste                                                           |https://www.amazon.com/Wonderway-Soldering-Electronics-CELLPHONE-Repairing/dp/B0BLSJQPR6/ref  |1      |10       |                                                                                  |
|Taxes deducted from amazon order                                       |N.A.                                                                                          |1      |5.6      |Shipping was free, this is the only extra thing amazon was charging               |
|                                                                       |                                                                                              |       |         |                                                                                  |
|USB4105-GF-A                                                           |https://www.digikey.com/en/products/detail/gct/USB4105-GF-A/11198441                          |2      |1.56     |Some of these components, I ordered extra because its LITTERLY cheaper to buy more|
|CP2102N-A02-GQFN28R                                                    |https://www.digikey.com/en/products/detail/silicon-labs/CP2102N-A02-GQFN28R/9863480           |2      |8.64     |                                                                                  |
|BMI270                                                                 |https://www.digikey.com/en/products/detail/bosch-sensortec/BMI270/9974486                     |2      |7.46     |                                                                                  |
|BMP390                                                                 |https://www.digikey.com/en/products/detail/bosch-sensortec/BMP390/16164575                    |2      |6.3      |                                                                                  |
|MMBT4401_R1_00001                                                      |https://www.digikey.com/en/products/detail/panjit-international-inc/MMBT4401-R1-00001/14661149|4      |0.64     |                                                                                  |
|OSTTE020104                                                            |https://www.digikey.com/en/products/detail/on-shore-technology-inc/OSTTE020104/2351816        |10     |3.61     |                                                                                  |
|PS1240P02BT                                                            |https://www.digikey.com/en/products/detail/tdk-corporation/PS1240P02BT/935924                 |2      |1.24     |                                                                                  |
|CL21B106KOQNNNE                                                        |https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B106KOQNNNE/3888530  |15     |0.53     |                                                                                  |
|C0805C104K5RACTU                                                       |https://www.digikey.com/en/products/detail/kemet/C0805C104K5RACTU/411169                      |20     |0.32     |                                                                                  |
|B320A-13-F                                                             |https://www.digikey.com/en/products/detail/diodes-incorporated/B320A-13-F/717692              |6      |1.56     |                                                                                  |
|ESD5Z5.0T5G                                                            |https://www.digikey.com/en/products/detail/onsemi/ESD5Z5-0T5G/5404303                         |10     |0.99     |                                                                                  |
|TPS565208DDCR                                                          |https://www.digikey.com/en/products/detail/texas-instruments/TPS565208DDCR/7776393            |2      |2.76     |                                                                                  |
|LD1117S33TR                                                            |https://www.digikey.com/en/products/detail/stmicroelectronics/LD1117S33TR/585766              |2      |0.68     |                                                                                  |
|ESP32-S3-WROOM-1-N8                                                    |https://www.digikey.com/en/products/detail/espressif-systems/ESP32-S3-WROOM-1-N8/15200089     |2      |10.98    |                                                                                  |
|CL21B105KBFNNNE                                                        |https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B105KBFNNNE/3886687  |10     |0.13     |                                                                                  |
|CL21A226MAYNNNE                                                        |https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21A226MAYNNNE/10479857 |3      |0.24     |                                                                                  |
|LTST-C170GKT                                                           |https://www.digikey.com/en/products/detail/liteon/LTST-C170GKT/269226                         |3      |0.3      |                                                                                  |
|AO3400A                                                                |https://www.digikey.com/en/products/detail/alpha-omega-semiconductor-inc/AO3400A/1855772      |10     |2.82     |                                                                                  |
|MLZ2012P220WT000                                                       |https://www.digikey.com/en/products/detail/tdk-corporation/MLZ2012P220WT000/4327893           |2      |0.2      |                                                                                  |
|CRCW08051K00FKEA                                                       |https://www.digikey.com/en/products/detail/vishay-dale/CRCW08051K00FKEA/1175637               |2      |0.2      |                                                                                  |
|RMCF0805FT22K1                                                         |https://www.digikey.com/en/products/detail/stackpole-electronics-inc/RMCF0805FT22K1/1760211   |10     |0.07     |                                                                                  |
|RMCF0805FT10K0                                                         |https://www.digikey.com/en/products/detail/stackpole-electronics-inc/RMCF0805FT10K0/1760676   |16     |0.21     |                                                                                  |
|RC0805JR-075K1L                                                        |https://www.digikey.com/en/products/detail/yageo/RC0805JR-075K1L/728338                       |10     |0.08     |                                                                                  |
|W25Q128JVSIM                                                           |https://www.digikey.com/en/products/detail/winbond-electronics/W25Q128JVSIM/6819721           |2      |3.94     |                                                                                  |
|RC0805FR-072K2L                                                        |https://www.digikey.com/en/products/detail/yageo/RC0805FR-072K2L/727676                       |10     |0.1      |                                                                                  |
|RC0805FR-0747K5L                                                       |https://www.digikey.com/en/products/detail/yageo/RC0805FR-0747K5L/727975                      |10     |0.1      |                                                                                  |
|RT0805BRD0759R7L                                                       |https://www.digikey.com/en/products/detail/yageo/RT0805BRD0759R7L/7708567                     |2      |0.32     |                                                                                  |
|RC0805FR-07330RL                                                       |https://www.digikey.com/en/products/detail/yageo/RC0805FR-07330RL/727866                      |10     |0.1      |                                                                                  |
|Dijikey Shipping                                                       |N.A.                                                                                          |1      |7        |                                                                                  |
|Sales tax + terrifs (Dijikey)                                          |N.A.                                                                                          |1      |8        |                                                                                  |
|                                                                       |                                                                                              |       |         |                                                                                  |
|JLCPCB 4 Layer PCB + stencil + Global Standard Dirrect Line + sales tax|JLC PCB                                                                                       |5      |33       |                                                                                  |
|                                                                       |                                                                                              |       |         |                                                                                  |
|JLC PCB order                                                          |33                                                                                            |       |         |                                                                                  |
|                                                                       |                                                                                              |       |         |                                                                                  |
|Amazon Order                                                           |65.6                                                                                          |       |         |                                                                                  |
|                                                                       |                                                                                              |       |         |                                                                                  |
|Dijikey Order                                                          |71.08                                                                                         |       |         |                                                                                  |
|                                                                       |                                                                                              |       |         |                                                                                  |
|Total Cost                                                             |169.68                                                                                        |       |         |                                                                                  |

