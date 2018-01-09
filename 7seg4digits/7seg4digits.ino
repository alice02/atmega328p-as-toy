#include <FlexiTimer2.h>

#define INTERVAL 1

// segment patterns
const int table[10][8] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW,  LOW }, // 0
  {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW }, // 1
  {HIGH, HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, LOW }, // 2
  {HIGH, HIGH, HIGH, HIGH, LOW,  LOW,  HIGH, LOW }, // 3
  {LOW,  HIGH, HIGH, LOW,  LOW,  HIGH, HIGH, LOW }, // 4  
  {HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, HIGH, LOW }, // 5
  {HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH, LOW }, // 6
  {HIGH, HIGH, HIGH, LOW,  LOW,  HIGH, LOW,  LOW }, // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW }, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH, LOW }, // 9
};

// pin assign (each anode)
// A, B, C, ..., DP
const int pin[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// pin assign (each cathode)
const int cathode[4] = {10, 11, 12, 13};

// counter
volatile int count = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  FlexiTimer2::set(1, dispNumbers); // 500ms period
  FlexiTimer2::start();
}


// the loop function runs over and over again forever
void loop() {
  int i, j;
  for (i = 0; i < 10000; i++) {
    delay(1000);
    count++;
  }
}

void dispNumbers() {
  int i, numbers;
  numbers = count;
  for (i = 0; i < 4; i++) {
    disp7seg(numbers % 10);
    digitalWrite(cathode[4-1-i], HIGH);
    delay(0.5);
    digitalWrite(cathode[4-1-i], LOW);   // turn the LED on (HIGH is the voltage level)    
    numbers /= 10;
  }
}

void disp7seg(int number) {
  int i;
  for (i = 0; i < 8; i++) {
    digitalWrite(pin[i], table[number][i]);
  }
}

