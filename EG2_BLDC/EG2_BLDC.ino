#include <Servo.h>
Servo BLDC;
byte bldc_pin = 9;
byte pot_pin = A0;

void setup() 
{
  BLDC.attach(bldc_pin);
  BLDC.writeMicroseconds(1500); // make the ESC high
  delay(5000); // delay to power up
}

void loop() 
{
  int val = analogRead(0); // read input from potentiometer.
  int pwm = map(val, 0, 1023, 1100, 1900); // maps potentiometer values to PWM value.
  BLDC.writeMicroseconds(pwm); // Send signal to ESC.
}
