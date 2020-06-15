# Temperature-and-humidity-module-for-MagicMirror2-with-SHT31-D
Modified from MMM-HDC1080 module

MagicMirror2 https://magicmirror.builders/

MMM-HDC1080 module: https://github.com/MichaelF1/MMM-HDC1080

1. install 3rd party module MMM-HDC1080 first
2. replace the ReadHDC1080_Pi.c
3. compile with command cc -Wall ReadHDC1080.c -o ReadHDC1080 -lwiringPi
4. enable I2C interface
5. update MagicMirror2 config file
6. all set
