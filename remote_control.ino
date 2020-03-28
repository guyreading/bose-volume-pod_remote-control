/*
  IR Receiver Demonstration 1
  IR-Rcv-Demo1.ino
  Demonstrates IR codes with IR Receiver
  Displays results on Serial Monitor

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>


// Define sensor pin
const int RECV_PIN = 9;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){
 
        switch(results.value){
          case 0xE0E028D7: //Green Keypad Button - volume up
              digitalWrite(4, LOW);  //assumes 7 and 4 are already high: goes 6 & 7
              digitalWrite(7, HIGH); 
              digitalWrite(5, HIGH);
              delay(50);
              digitalWrite(7, LOW); // 5 & 6
              digitalWrite(6, HIGH);
              delay(50);
              digitalWrite(5, LOW); //4 & 5
              digitalWrite(4, HIGH);
              delay(50);
              digitalWrite(6, LOW); //7 & 4
              digitalWrite(7, HIGH);
              break;

          case 0xE0E036C9: //Red Keypad Button - volume down
              digitalWrite(7, LOW);  //assumes 7 and 4 are already high: goes 4 & 6
              digitalWrite(4, HIGH); //yellow
              digitalWrite(6, HIGH); //yellow
              delay(50);
              digitalWrite(4, LOW); //5 & 6
              digitalWrite(5, HIGH); //green
              delay(50);
              digitalWrite(6, LOW); // 6 & 7
              digitalWrite(7, HIGH); //orange
              delay(50);
              digitalWrite(5, LOW); //7 & 4
              digitalWrite(4, HIGH); //white
              break;
        }
        
        irrecv.resume();
  }
}
