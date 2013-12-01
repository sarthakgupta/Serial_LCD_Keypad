5 wire interface of LCD and keypad 
==================================


I have used 2 serial 8-bit shift registers(74hct595), which takes serial data, latch clock and serial clock, on giving them 8-bit serial data we can have 8- bit parallel data out of 74hct595, when these two shift registers are placed in cascade manner (you can refer schematic) we can have 16- bit parallel data from 16-bit serial input. I have used keypad in 8x2 format so I need 8 data lines as input to keypad and will be having 2 data lines as output from keypad. When LCD is used in 4-bit mode we need 6 data lines (D4,D5,D6,D7,RS,EN).So I require 3 data lines for shift registers and 2 data lines for keypad, thus 5 data lines to control LCD and Keypad. I have demonstrated it with Arduino Uno and also on the Arduino based protoboard("LOLduino"). It works even if your controller works at 3.3V, because when you give input as 5V to the Vcc of the shift registers, it take 3.3V as high logic.

Cheers!!

