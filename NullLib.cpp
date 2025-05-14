//
// Created by mashi on 14.05.2025.
//

#include "NullLib.h"
#include <Adafruit_PN532.h>

// Konstruktor-Implementierung
NullLib::NullLib() {

}



void NullLib::ReadNFC(uint8_t *uid, uint8_t &uidLength) {
    // Initialisiere UID mit Nullen
    memset(uid, 0, 7);  // Setzt alle 7 Bytes auf 0

    bool tagRead = false;
    unsigned long readStart = millis();

    while(!tagRead && (millis() - readStart < 10000)) {  // 10 Sekunden Timeout
        if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 500)) {
            // UID speichern
            memcpy(lastUID, uid, uidLength);
            lastUIDLength = uidLength;

            tagRead = true;
        }
    }
}



