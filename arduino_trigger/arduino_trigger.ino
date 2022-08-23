//Sinisa Steblaj, 2022, Arduino lightning switch for Canon400D
//Based on
//Michael Klements
//13 December 2016

int shutterPin = 2;  //Assign the LDR and optocoupler pins
int triggerPin = 0;
int triggerPointPin = 1;
int triggered =0;
int triggerPoint = 0;
int ledPin = 13;
bool ledOff = false;

void setup() 
{ 
  pinMode(ledPin, OUTPUT);       // LED pin output, if lights on, the surrounding light is to high and TriggerPoint is never achieved
  digitalWrite(ledPin, LOW);
  pinMode(shutterPin,OUTPUT);    //Define the shutter pin as an output
  digitalWrite(shutterPin,LOW);  //Set the shutter pin to low / off / no voltage
  triggerPoint = map(analogRead(triggerPointPin), 0, 1023, 0, 1023); //Read the output from the potentiometer
  Serial.begin(9600);
}

void loop() 
{ 

  triggered = map(analogRead(triggerPin), 0, 1023, 0, 1023);  //Read the output from the LDR
  triggerPoint = map(analogRead(triggerPointPin), 0, 1023, 0, 1023);
  Serial.print(ledOff);
  Serial.print("\t");
  Serial.print(triggered);
  Serial.print("\t");
  Serial.print(triggerPoint);
  Serial.println();
  if (triggered >= triggerPoint)  //If light is detected, trigger the camera
  {
    delay(50);    //Wait for lightning to be the brightest
    digitalWrite(shutterPin,HIGH);  //Trigger camera
    delay(1000);
    digitalWrite(shutterPin,LOW);   //Reset camera trigger output for next photo
    triggered = 0;
    if (ledOff) {
      ledOff = false;
      digitalWrite(ledPin, HIGH);
    }
  } else {
    ledOff = true;
    digitalWrite(ledPin,LOW);
  }
}
