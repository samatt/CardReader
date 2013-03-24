#ifndef CardReader_h_
#define CardReader_h_

#include <Arduino.h>

class CardReader {
  public:
    //CardReader(int protocol); // perhaps a choice between Weigand and C&D
    //CardReader();
    CardReader(int dataPin, int clockPin);
    bool cardRead();
    void readBit();
    void clearData();
    long getCardId();
    int getFacilityNumber();
    long getIdNumber();

    //These pins are labelled on the card reader.
    int clockPin;
    int dataPin;
    long idNumber;
    volatile int count;
    volatile byte data[300];

};


#endif
