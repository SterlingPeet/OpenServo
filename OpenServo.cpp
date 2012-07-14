
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

#include "OpenServo.h"

OpenServo::OpenServo(Wire wire, int address)
{
  _wire = wire;
  _address = address;
}

/* ================ Public methods ================ */

void OpenServo::setPosition()
{
  _OpenServoWrite16(OPENSERVO_SEEK, int data);
}


unsigned int OpenServo::getPosition()
{
  return _OpenServoRead16(OPENSERVO_POSITION);
}


void OpenServo::enable()
{
  _OpenServoCommand8(OPENSERVO_PWM_ENABLE);
}

void OpenServo::disable()
{
  _OpenServoCommand8(OPENSERVO_PWM_DISABLE);
}

/*
OpenServo::reverseSeekEnable()
{
}

OpenServo::reverseSeekDisable()
{
}*/

/* ================ Private methods ================ */

/*OpenServo::_setReverseSeek()
{
  
}*/

void OpenServo::_OpenServoWrite16(byte reg, int data)
{
  // write a 16 bit register
  _OpenServoTransactionInit(reg);
 
  OS_WRITE(data >> 8);    //  high byte 
  OS_WRITE(data & 0xff);  //  low byte

  _wire.endTransmission();
}

unsigned int OpenServo::_OpenServoRead16(byte reg)
{
  // read a 16 bit register 
  _OpenServoTransactionInit(reg);
 
  unsigned int data;
  
  _wire.requestFrom(_address, 2);
  if (_wire.available())
    data = OS_READ() << 8; // high byte 
  if (_wire.available())   
    data |= OS_READ();     //  low byte
 
  _wire.endTransmission();
 
  return data;
}

void OpenServo::_OpenServoCommand8(byte reg)
{
  // Send an 8 bit servo command
  _OpenServoTransactionInit(reg);
  _wire.endTransmission();
}

void OpenServo::_OpenServoTransactionInit(byte reg)
{
  // init an i2c transmission
  _wire.beginTransmission(_address);
  OS_WRITE(reg);
}

