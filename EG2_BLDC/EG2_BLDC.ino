#include <Servo.h>
Servo BLDC;

void setup() 
{
  BLDC.attach(9);
  BLDC.writeMicroseconds(1500); // make the ESC high
  delay(5000); // delay to power up
}

void loop() 
{
  int val = analogRead(0); // read input from potentiometer.
  int pwm = map(val, 0, 1023, 0, 180); // maps potentiometer values to PWM value.
  BLDC.write(pwm); // Send signal to ESC.
}
