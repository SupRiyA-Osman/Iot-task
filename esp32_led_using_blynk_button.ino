//Prateek
//www.prateeks.in
//https://www.youtube.com/c/JustDoElectronics

#define BLYNK_TEMPLATE_ID "TMPL6GydspOy_"
#define BLYNK_DEVICE_NAME "LED BLINK"
#define BLYNK_AUTH_TOKEN "FxFKRld584DQpT-6OOn2vPKwZyUaFBEZ"
#define BLYNK_TEMPLATE_NAME "LED BLINK"

#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Intellier-KB";
char pass[] = "IntellierKb@4321";

BlynkTimer timer;


#define button1_pin 4


#define led1_pin 5


int led1_state = 0;


#define button1_vpin    V1

BLYNK_CONNECTED() {
  Blynk.syncVirtual(button1_vpin);

}

BLYNK_WRITE(button1_vpin) {
  led1_state = param.asInt();
  digitalWrite(led1_pin, led1_state);
}
void setup()
{

  Serial.begin(115200);
  pinMode(button1_pin, INPUT_PULLUP);
 
  pinMode(led1_pin, OUTPUT);

  digitalWrite(led1_pin, HIGH);

  Blynk.begin(auth, ssid, pass);
 
}

void loop()
{
  Blynk.run();
  timer.run();
  
  listen_push_buttons();
}

void listen_push_buttons(){
    if(digitalRead(button1_pin) == LOW){
      delay(200);
      control_led(1);
      Blynk.virtualWrite(button1_vpin, led1_state); 
    }
    
}

void control_led(int led){

  if(led == 1){
    led1_state = !led1_state;
    digitalWrite(led1_pin, led1_state);
    Serial.print("led1 State = ");
    Serial.println(led1_state);
    delay(50);
  }

 
  
}