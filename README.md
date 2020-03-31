# bose-volume-pod_remote-control
This project is to control your bose volume control pod using a TV remote control. It is split into 2 sections:

1. Identifying which buttons you'd like to map to volume up & volume down & finding out their HEX key that your specific remote control sends (this is achieved using "finding_out_codes").

2. Mapping the vol up and vol down hex keys to the stepper motor clockwise and anti-clockwise movement (this is achieved using "remote_control").


The wiring for the stepper motor and IR sensor is straight-forward/can be deduced from the pins used in the code, although I am planning on putting a wire diagram up soon. 


A video showing the set-up can be found [here](https://www.youtube.com/watch?v=74JBGCSBqmY "Volume control video")

This code depends on [arduino-IRremote](https://github.com/z3t0/Arduino-IRremote)


Hardware:

-> Nema 17 Stepper Motor

-> KY-022 Infrared IR Sensor




