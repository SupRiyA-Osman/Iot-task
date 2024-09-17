#include <Stepper.h>
int motorspeed=10;
Stepper myStepper(2048,3,4,5,6);

void setup() {
myStepper.setSpeed(motorspeed);
myStepper.step(-1024);
}

void loop() {
myStepper.step(2048);
delay(1000);
myStepper.step(-2048);
delay(1000);
}
