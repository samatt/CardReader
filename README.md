# HID Card Reader Arduino Library

## Overview
This library will allow you to read iClass DH cards with a multiClass HID Card Reader.

These card readers come in two flavors: Wiegand protocol or Clock and Data protocol. 

**This library currently supports the Clock and Data protocol**. Readers that use the Clock and data protocol should have a 'CD' in the model name.



At the moment you need to include  


`void readBit() {
reader.readBit();
}`


 in the main sketch and attach it to an interrupt in setup()
 
`attachInterrupt(1, readBit, RISING);`


You'll see in the example file there is a wrapper function for attachInterrupt() in the setup function. We will work on 


