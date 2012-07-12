
/**
 * OpenServo Arduino/Wire Communication Library
 *
 *   This library communicates with an OpenServo on the i2c bus using the
 * OpenServo i2c API (http://www.openservo.com/APIGuide).  You must create
 * an instance of Wire to pass to the library.  The library will grab and
 * release the i2c bus during its communication cycles, but will not lock
 * up the bus outside of the library, so you can use the Wire instance to
 * communicate with other i2c devices on the bus, or send special commands
 * to an OpenServo, should you find this library lacking in some way.
 *
 * Copyright 2012 Sterling Lewis Peet <sterling.peet@gatech.edu>
 *
 * This work is licensed under the Creative Commons
 * Attribution-NonCommercial-ShareAlike 3.0 Unported License. To view a copy of
 * this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ or
 * send a letter to:
 *
 * Creative Commons
 * 444 Castro Street, Suite 900
 * Mountain View, California, 94041, USA.
 *
 * Other Licensing is available upon request.
 *
 */

#ifndef OPENSERVO_H
#define OPENSERVO_H

#include <Wire.h>

// OpenServo registers & commands
#define OPENSERVO_POSITION    0x08
#define OPENSERVO_SEEK        0x10

#define OPENSERVO_PWM_ENABLE  0x82
#define OPENSERVO_PWM_DISABLE 0x83

// servo i2c address
#define DEFAULT_SERVO_ADDRESS 0x10

// Wire compatability macro
#if (ARDUINO >= 100)
 #define OS_WRITE(X) Wire.write(X)
 #define OS_READ() Wire.read()
#else
 #define OS_WRITE(X) Wire.send(X)
 #define OS_READ() Wire.recieve()
#endif 


class OpenServo
{
  public:
    OpenServo(Wire wire, int address);
    void setPosition();
    unsigned int getPosition();
    void enable();
    void disable();
  private:
    Wire _wire;
    int _address;
    //byte _reverseSeek;
    void _OpenServoWrite16(byte reg, int data);
    unsigned int _OpenServoRead16(byte reg);
    void _OpenServoCommand8(byte reg);
    void _OpenServoTransactionInit(byte reg);
};

#endif
