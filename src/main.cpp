#include <Arduino.h>

// put function declarations here:
const int LED = 1;
const int BUTTON = 6;

int val = 0;
int oldVal = 0;
int state = 0;
int brightness = 128;
unsigned long startTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);

  if((val== HIGH) && (oldVal == LOW)){
    state = 1 - state;
    startTime = millis();
    delay(20);
  }
  if((val == HIGH) && (oldVal == HIGH)) {
    if(state == 1 && (millis() - startTime) > 500){
      brightness++;
      delay(20);
      if(brightness > 255){
        brightness = 0;
      }
    }
  }

  oldVal = val;
  if(state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
}