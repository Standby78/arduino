#include <Servo.h>
 
int valueX = 0; // X-AXIS LECTURE
int valueY = 0; // Y-AXIS LECTURE
int pinJX = A0; // X-AXIS CONNECTED TO ANALOG PIN A0
int pinJY = A1; // Y-AXIS CONNECTED TO ANALOG PIN A1
Servo motor1; // DECLARE SERVO 1
Servo motor2; // DECLARE SERVO 2
int degree1 = 0; // SERVO 1 DEGREES
int degree2 = 0; // SERVO 2 DEGREES
 

int secondvalueX = 0; // X-AXIS LECTURE
int secondvalueY = 0; // Y-AXIS LECTURE
int secondpinJX = A2; // X-AXIS CONNECTED TO ANALOG PIN A0
int secondpinJY = A3; // Y-AXIS CONNECTED TO ANALOG PIN A1
Servo secondmotor1; // DECLARE SERVO 1
Servo secondmotor2; // DECLARE SERVO 2
int seconddegree1 = 0; // SERVO 1 DEGREES
int seconddegree2 = 0; // SERVO 2 DEGREES

 
void setup() {
Serial.begin(9600); // ACTIVATE THE COMMUNICATION WITH THE BUILD&CODE UNO BOARD
motor1.attach (6); // PWM 9 DIGITAL PIN CONNECTED TO SERVO 1
motor1.write (0);
motor2.attach (9); // PWM 10 DIGITAL PIN CONNECTED TO SERVO 2
motor1.write (0);
secondmotor1.attach (10); // PWM 9 DIGITAL PIN CONNECTED TO SERVO 1
secondmotor1.write (0);
secondmotor2.attach (11); // PWM 10 DIGITAL PIN CONNECTED TO SERVO 2
secondmotor1.write (0);
}
 
void loop() {
 
valueX = analogRead (pinJX); // STORES THE READINGS OF THE X-AXIS OF THE ANALOG PORT A0
valueY = analogRead (pinJY); // STORES THE READINGS OF THE Y-AXIS OF THE ANALOG PORT A1
 
degree1 = map(valueX, 0, 1023, 0, 180);
degree2 = map(valueY, 0, 1023, 0, 180);
 
motor1.write (degree2); // SEND DEGREES TO SERVO 3
motor2.write (degree1); // SEND DEGREES TO SERVO 4

secondvalueX = analogRead (secondpinJX); // STORES THE READINGS OF THE X-AXIS OF THE ANALOG PORT A0
secondvalueY = analogRead (secondpinJY); // STORES THE READINGS OF THE Y-AXIS OF THE ANALOG PORT A1
 
seconddegree1 = map(secondvalueX, 0, 1023, 0, 180);
seconddegree2 = map(secondvalueY, 0, 1023, 0, 180);
 
secondmotor1.write (seconddegree1); // SEND DEGREES TO SERVO 1
secondmotor2.write (seconddegree2); // SEND DEGREES TO SERVO 2

//Show on the screen the variables we are working with
Serial.print (secondvalueX); // SHOW ON SCREEN THE X-AXIS VALUES FROM 0 TO 1023
Serial.print("\t");
Serial.print (secondvalueY); // SHOW ON SCREEN THE Y-AXIS VALUES FROM 0 TO 1023
Serial.print("\t");
Serial.print (seconddegree1); // SHOW ON SCREEN THE X-AXIS VALUES FROM 0 TO 180
Serial.print("\t");
Serial.println(seconddegree2); // SHOW ON SCREEN THE Y-AXIS VALUES FROM 0 TO 180
}
