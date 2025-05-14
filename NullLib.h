#ifndef NullLib_h
#define NullLib_h

#include "Arduino.h"
#include <Adafruit_PN532.h>

class NullLib {
public:
    // Konstruktor
    NullLib();

    // Öffentliche Methoden
    void ReadNFC(uint8_t *uid, uint8_t &uidLength);


private:

};

#endif