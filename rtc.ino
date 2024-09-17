#include <Wire.h>
#include <RTClib.h>

// Create an RTC instance
RTC_DS3231 rtc;

void setup () {
  Serial.begin(9600);

  // Initialize the RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Check if the RTC lost power and if so, set the time
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // The following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // Alternatively, you can set the date and time manually:
     //rtc.adjust(DateTime(2024, 9, 4, 12, 0, 0)); // Year, Month, Day, Hour, Minute, Second
  }
}

void loop () {
  DateTime now = rtc.now();

  // Print the current date and time
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(1000); // wait for a second
}