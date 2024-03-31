
#ifndef _HelperLED_h
#define _HelperLED_h

#include "Arduino.h"

class HelperLED
{
public:

	// General class and object initialization stuff

    HelperLED();
    void init( int pin );
    void reset();
    
    // blink the LED with a 100 millisecond delay
    
    void blink();
    
    // flash the LED multiple times with 100 millisecond delay per flash
    
    void flash( int count );
    
    // turn the LED on and off
    
    void on();
    void off();
    
    // flash pseudo sos message
    
    void sos();
    
    // flash pulsing heart beat
    void heartBeat();
    
private:
    int _pin;
    bool _initialized;
};

#endif

