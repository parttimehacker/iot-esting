
#include "HelperLED.h"
#include "Arduino.h"

HelperLED::HelperLED()
{
    // assume not initialized and pin is invalid
    _initialized    = false;
    _pin            = -1;
}

// // // // //
// init one pin after validating
void HelperLED::init( int pin )
{
    _initialized = true;
    pinMode(pin, OUTPUT);
    _pin = pin;
}

// // // // //
// simply turn it off
void HelperLED::reset(  )
{
	off();
}

// // // // //
// flash LED
void HelperLED::blink()
{
    if (_initialized) {
        digitalWrite(_pin, HIGH);   // turn the LED on (HIGH is the voltage level)    
        //digitalWrite(_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);
        digitalWrite(_pin, LOW);   // turn the LED on (HIGH is the voltage level)   
    }
}


// // // // //
// blink it multiple times
void HelperLED::flash( int count )
{
    if (_initialized) {
        if ( (count>0) && (count < 10) ) {
            for (int i=0; i<count; i++) {
                digitalWrite(_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
                delay(100);
                digitalWrite(_pin, LOW);   // turn the LED on (HIGH is the voltage level)
                delay(100);
            }
        }
    }
}


// // // // //
// turn LED on
void HelperLED::on()
{
    if (_initialized) {
        digitalWrite(_pin, HIGH);
        //Serial.println("Light On");
    }
}

// // // // //
// turn LED off
void HelperLED::off()
{
    if (_initialized) {
        digitalWrite(_pin, LOW);
    }
}

// // // // //
// sos message
void HelperLED::sos()
{
    if (_initialized) {
        flash(3);
        delay(100);
        on();
        delay(300);
        off();
        delay(100);
        on();
        delay(300);
        off();
        delay(100);
        on();
        delay(300);
        off();
        delay(100);
        flash(3);
    }
}

// // // // //
// sos message
void HelperLED::heartBeat()
{
	blink();
}
  