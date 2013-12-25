#include <cstdio>
#include "and.h"
#include "not.h"
#include "shift.h"
Int main()
{
const int latchPin = 3; 
const int clockPin = 2; 
const int dataPin = 1; 
  
void setup() { 
  pinMode(latchPin, OUTPUT); 
  pinMode(dataPin, OUTPUT);   
  pinMode(clockPin, OUTPUT); 
  Serial.begin(9600); 
  Serial.println("reset"); 
} 
  
void loop() { 
  unsigned int outputStates = 0; 
    for (int thisPosition = 0; thisPosition < 16; thisPosition++) { 
    digitalWrite(latchPin, LOW); 
      bitWrite(outputStates, thisPosition, HIGH); 
      byte highPins = highByte(outputStates); 
    byte lowPins = lowByte(outputStates); 
     shiftOut(dataPin, clockPin, MSBFIRST, lowPins); 
    shiftOut(dataPin, clockPin, MSBFIRST, highPins);   
  
    digitalWrite(latchPin, HIGH); 
    delay(250); 
  } 
}
}

