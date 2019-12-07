// example to test the mbed Lab Board lcd lib with the mbed rtos
// Pot1 changes the contrast
// Pot2 changes the speed of the sin wave

#include "mbed.h"
#include "rtos.h"
#include "stdio.h"
#include "SDFileSystem.h"
#include "wave_player.h"


SDFileSystem sd(p5, p6, p7, p8, "sd");
AnalogOut DACout(p18);
wave_player waver(&DACout);

// mutex to make the speaker function thread safe
Mutex spk_mutex;

// Thread 6
// Speaker
void speaker_thread(void const *args)
{
    FILE *wave_file;
    while(true) {         // thread loop
        
        spk_mutex.lock();
        wave_file=fopen("/sd/bubble.wav","r");
        spk_mutex.unlock();
        
        waver.play(wave_file);
        
        spk_mutex.lock();
        fclose(wave_file);
        spk_mutex.unlock();
        
        Thread::wait(500); // wait 
    }
}
    

int main()
{

    Thread t6(speaker_thread); //start thread6
    
    while(true) {       // main is the next thread
       Thread::wait(1000); // wait 0.5s
    } 
    
}
