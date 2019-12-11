#include "Servo.h"
#include "mbed.h"
#include "motordriver.h"
#include "rtos.h"
#include "stdio.h"
#include "SDFileSystem.h"
#include "wave_player.h"

volatile bool alarm  = false;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

Ticker wing;
Ticker bark;

RawSerial pi(USBTX, USBRX);
Servo myservo(p23);      
Motor wingL(p22, p9, p10, 1); // pwm, fwd, rev
Motor wingR(p21, p12, p11, 1);//wings move in opposite directions
//reverse one motor's leads when wiring
Motor wheelL(p24, p14, p13, 1);
Motor wheelR(p25, p16, p15, 1);//wheels move in the same direction
PwmOut led1(p23);
PwmOut led2(p26);
AnalogIn flag(p20);

SDFileSystem sd(p5, p6, p7, p8, "sd");
AnalogOut DACout(p18);
wave_player waver(&DACout);
Mutex spk_mutex;
Mutex servo_mutex;
Mutex wing_mutex;
Mutex alrm_mutex;
char temp;

void startMotors() {
    for (float s= -1.0; s < 1.0 ; s += 0.002) 
        {
            wingL.speed(s);
            wingR.speed(s);
            wait(0.0005);
        }

    for (float x = -1.0; x< 1.0; x += 0.1)
        {
            wheelL.speed(x);
            wheelR.speed(x);
            wait(0.2);
        }
}

void stopMotors() {
    wingL.speed(0);
    wingL.speed(0);
    
    wheelL.speed(0);
    wheelR.speed(0);
}

void startSound() {
    FILE *wave_file;
    wave_file=fopen("/sd/sound00.wav","r");
    waver.play(wave_file);
    fclose(wave_file);
}

void piDetectInvader()
{
    while(true)
    {
        while(pi.readable())
        {
            temp = pi.getc();
            pi.putc(temp);
            
            if(temp == '1') { 
                alarm = true;
                led1=1;
                led2=1;
                startMotors();
                startSound();

            }
            if(temp == '0') {
                alarm = false;
                led1=0;
                led2=0;
                stopMotors();
            }
        }
    }
}

int main() 
{   
    pi.baud(9600);
    pi.attach(&piDetectInvader, Serial::RxIrq);

    while(true) { } 
}