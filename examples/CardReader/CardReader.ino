#include <CardReader.h>

CardReader reader(3, 2);
long cardNumber = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(1, readBit, RISING);
}


void loop () {
  if (reader.cardRead()) {
    Serial.print("Card ID: ");
    Serial.println(reader.getIdNumber());
    Serial.print("Facility Number: ");
    Serial.println(reader.getFacilityNumber());
  }
  
}


void readBit() {
  reader.readBit();
}

