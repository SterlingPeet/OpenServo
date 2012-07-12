OpenServo
=========

OpenServo Arduino/Wire Communication Library

  This library communicates with an OpenServo on the i2c bus using the
OpenServo i2c API (http://www.openservo.com/APIGuide).  You must create
an instance of Wire to pass to the library.  The library will grab and
release the i2c bus during its communication cycles, but will not lock
up the bus outside of the library, so you can use the Wire instance to
communicate with other i2c devices on the bus, or send special commands
to an OpenServo, should you find this library lacking in some way.

Copyright 2012 Sterling Lewis Peet <sterling.peet@gatech.edu>

This work is licensed under the Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. To view a copy of
this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ or
send a letter to:

Creative Commons
444 Castro Street, Suite 900
Mountain View, California, 94041, USA.

Other Licensing is available upon request.
