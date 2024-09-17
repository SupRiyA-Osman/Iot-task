#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // Slave Select pin for RFID
#define RST_PIN 9  // Reset pin for RFID

MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  SPI.begin();  // Initialize SPI bus
  rfid.PCD_Init();  // Initialize RFID reader

  Serial.println("Place your RFID tag on the reader...");
}

void loop() {
  // Look for new RFID cards
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    Serial.print("Tag UID: ");

    // Print RFID UID
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);  // Print each byte of the UID in hexadecimal
    }
    Serial.println();  // Move to the next line after printing the UID

    // Halt PICC (stop reading the tag)
    rfid.PICC_HaltA();
  }
}