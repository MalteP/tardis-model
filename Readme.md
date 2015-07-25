# TARDIS

CNC cut and engraved model of the TARDIS with light & sound circuit

This model is made of 4mm plywood, engraved and cut using a CNC machine.

![](./pictures/Tardis.jpg =640x)

A small circuit board is added to provide light and sound effects (samples not included).
I am using a ATTiny44 microcontroller and the chinese WTV20 sd card wave player module.

The first sample (named 0000.ad4 on the sdcard) should be the TARDIS woosh noise.
Light will fade in, light on top will fade on and off until the sound stops. Also the lights will fade off then.
If there are more samples on the sdcard, they will also played, the light on top will not fade but stay switched on during it.
I've used it to add some random Dr. Who quotes. 
The circuit will detect the last sound (measuring the time of the WTV20 busy pin) and continue with the first sound again.

## Software used

For the CAD files i've been using Artcam which is a very nice and easy to use program.
You can export the files directly for your CNC machine. Use a 2mm spiral cut tool and a v-bit for engraving.

The PCB is made using Target! 3001, etched and hand milled.

## Compiling the firmware

To compile the firmware install the AVR-GCC toolchain. Solder MISO/MOSI/SCK/Reset wires to the circuit board, compile and flash using make, make fuse and make program.


Feel free to contact me if you have any questions.
