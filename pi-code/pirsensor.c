/********************************************************************************************
*Filename      : pirsensor.c
*Description   : alarm system
*Author        : Alan
*Website       : www.osoyoo.com
*Update        : 2017/07/04

Edited: Jamie Lee and Jingyi Yu
Date: 12/09/2019
********************************************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

#define AlarmPin	        4 // GPIO 23
#define PIRPin0                 2 // GPIO 17
#define PIRPin1			1 // GPIO 18
#define PIRPin2 		3 // GPIO 22
#define alarmpin		5 // GPIO 24

// To compile, run in terminal: gcc -Wall -o pirsensor pirsensor.c -lwiringPi

int main(void)
{
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		exit(1);
	}
	
	pinMode(AlarmPin, OUTPUT);
	pinMode(PIRPin0,INPUT);
	pinMode(PIRPin1, INPUT);
	pinMode(PIRPin2, INPUT);

	printf("\n");
	printf("========================================\n");
	printf("|              Alarm                   |\n");
	printf("|    ------------------------------    |\n");
	printf("|        PIR connect to GPIO0          |\n");
	printf("|                                      |\n");
	printf("|        Buzzer connect to GPIO1       |\n");
	printf("|                                      |\n");
	printf("|                                OSOYOO|\n");
	printf("========================================\n");
	printf("\n");
	
	// initalize connection to mbed
	int fd = -1;
	
	fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY);
	//open mbed's USB virtual com port
	if (fd == -1) {
		printf("open_port: Unable to open /dev/ttyACM - ");
		return -1;
	}
	// Turn off blocking for reads, use (fd, F_SETFL, FNDELAY) if you want that
        fcntl(fd, F_SETFL, 0);
	//Linux Raw serial setup options
	struct termios options; 
	tcgetattr(fd,&options);   //Get current serial settings in structure
	cfsetspeed(&options, B9600);   //Change a only few
	options.c_cflag &= ~CSTOPB;
	options.c_cflag |= CLOCAL;
	options.c_cflag |= CREAD;
	cfmakeraw(&options);
	tcsetattr(fd,TCSANOW,&options);    //Set serial to new settings
	sleep(1);
  
	int x, y, z;
	
	while(1){
	   if((x = digitalRead(PIRPin0)) || (y =digitalRead(PIRPin1)) || (z=digitalRead(PIRPin2))) {
		digitalWrite(AlarmPin, HIGH);
		printf("\n");
		printf("|       alarm...   |\n");
		
		if (x) {
			printf("PIRPin0 triggered.\n");
		} if (y) {
			printf("PIRPin1 triggered.\n");
		} if (z) {
			printf("PIRPin2 triggered.\n");
		}
		
		// Send signal to mbed when pir sensor is triggered
		write(fd,"1",1);        // on
		
		delay(1000);
		}
		else{
		digitalWrite(AlarmPin, LOW);
		printf("\n");
		printf("|   no alarm...    |\n");
		write(fd,"0",1);        // off
		delay(1000);
		}
	}
	// Don't forget to clean up and close the port
        tcdrain(fd);
        close(fd);
        return 0;
}

