/*
 * Read temperature and humidity from sensor Adafruit SHT31-D for MagicMirror2
 */
#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <string.h>
#include <linux/i2c-dev.h>
#include <sys/stat.h>


float fTemp=0, fHumid=0;

int main()
{
	// Create I2C bus
	int file;
	file = open("/dev/i2c-1", O_RDWR);
	// Get I2C device, default SHT31 I2C address is 0x44(68)
	ioctl(file, I2C_SLAVE, 0x44);

	// Send high repeatability measurement command
	// Command msb, command lsb(0x2C, 0x06)
	char config[2] = {0};
	config[0] = 0x2C;
	config[1] = 0x06;
	write(file, config, 2);
	sleep(1);

	// Read 6 bytes of data
	// temp msb, temp lsb, temp CRC, humidity msb, humidity lsb, humidity CRC
	char data[6] = {0};
	read(file, data, 6);
	close(file);
	
	// Convert the data
	fTemp = (((data[0] * 256) + data[1]) * 315.0) / 65535.0 - 49.0;
	fHumid = (((data[3] * 256) + data[4])) * 100.0 / 65535.0;
	printf("%.3f,%.3f\n", fTemp, fHumid);
	return(0);
}
