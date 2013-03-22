#ifndef CardReader_h_
#define CardReader_h_

#include <Arduino.h>

class CardReader {
  public:
    //CardReader(int protocol); // perhaps a choice between Weigand and C&D
    //CardReader();
    CardReader(int dataPin, int clockPin);
    void readCard();
    void readBit();
    void clearData();

    int clockPin;
    int dataPin;
    int facilityNumber;
    long idNumber;
    bool idPresent;
    volatile int count;
    volatile byte data[300];
};


#endif
