/*  
   Card reader decoder
   
   The card reader used is the HID-RP40-CGNNN.
   The RP40 comes in two flavours, one uses the WEIGAND protocol the other uses Clock and Data. 
   The HID-RP40-CGNNN uses clock and data and the code in this sketch has been written with that in mind.
   For more information on how to read the WEIGAND format go to this website:
   http://www.pagemac.com/azure/arduino_wiegand.php
   
   This sketch has only been tested with HID iClass DH cards
   
   For more information related to the different formats HID readers provide 
   data download this pdf:
   http://rfid-reader.googlecode.com/files/Open%20Format.pdf
   
   Format from raw bit stream:
   
   <25 leading zeros>  xx yyyy yyyy yyyy zzzz zzzz zzzz zzzz zzzz aaaa<trailing zeros>
   
   x: start
   y: Facility Number
   z: Card ID
   a: Parity Check stuff
   
   In this sketch only the y and z bits are being decoded and the rest are being ignored.
   d
   created 22 Mar 2013
   by Surya Mattu and Luis Daniel
   
*/

#include "CardReader.h"


CardReader::CardReader(int _clockPin, int _dataPin) {
  clockPin = _clockPin;
  dataPin = _dataPin;
  pinMode(dataPin, INPUT);
  pinMode(clockPin, INPUT);
  //attachInterrupt(1, readBit, RISING);
  //Serial.begin(9600);
  for (int a = 0; a < 200; a++) 
  {
    data[a] = 0;
  }
  //interrupts();
}

bool CardReader::cardRead() {
  //TODO: Make this less arbitrary. 
  //211 seems to be the number of bits that come in per tap.
  if (count >= 211) {
    //Serial.println("READ COMPLETE!");
    facilityNumber = 0; 
    for (int i = 27; i <39; i++) 
    {
      facilityNumber <<= 1;
      facilityNumber |= data[i];
    }
    idNumber = 0;
    for (int j = 39; j <59; j++) 
    {
      idNumber <<= 1;
      idNumber |= data[j];
    }
    clearData();
    return true;
  } else {
    return false;
  }



}

void CardReader::clearData(){
  count = 0;
  for (int a = 0; a < 200; a++) 
  {
    data[a] = 0;
  }
}


int CardReader::getFacilityNumber(){
  return facilityNumber; 
}

long CardReader::getIdNumber(){
  return idNumber;
  
}

void CardReader::readBit() {
  if (digitalRead(dataPin) == HIGH)
  {
    data[count] = 0;
  }
  else
  {
    data[count] = 1;
  }
  count++;
}








