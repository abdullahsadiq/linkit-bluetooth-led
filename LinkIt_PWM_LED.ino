#include <LBT.h>
#include <LBTServer.h>

int ledPin = 9; //Pin the LED strip is connected to the LinkIt ONE
int value;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);   //Initialize serial port
Serial.println("Started LED PWM control program");
pinMode(ledPin,OUTPUT);   //Set ledPin as output
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available() == 0){}   //Wait until user inputs something
value = Serial.parseInt();
Serial.println(value);
LBTServer.write(value);

if (value >=0 && value <=1023){
  analogWrite(ledPin,value);  //Writes the value saved to the ledPin
  }
else {
  Serial.println("Error! Type a value between 0-1023");
  LBTServer.write("Error! Type a value between 0-1023");
  }

}
