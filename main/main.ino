#define dataSignal 7
#define shiftRegisterClock 6
#define storageRegisterClock 5


void setup() {
  for(int pin = 5; pin <= 7; pin ++) {
    pinMode(pin, OUTPUT);
  }
}


void displayBinary(int value) {
  digitalWrite(storageRegisterClock, LOW);
  shiftOut(dataSignal, shiftRegisterClock, MSBFIRST, value);
  digitalWrite(storageRegisterClock, HIGH);
}
  

void testNumbers(int delayValue) {
  // Highest number that can be shown in 8 bits is 255
  
  for(int number = 0; number <= 255; number = number + 1) {
    displayBinary(number);
    delay(delayValue);
  }
}


void loop() {
  testNumbers(100);
}
