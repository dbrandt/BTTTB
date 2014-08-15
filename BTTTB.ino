/*
  BTTTB - Better Than That Tennis Ball
*/

#define echo 2 // Echo Pin
#define trigger 4 // Trigger Pin
#define led_OK 13
#define led_CLOSE 12

volatile long echo_hit_time;
volatile long echo_death_time;
volatile int distance;

void echo_int() {
  switch (digitalRead(echo)) {
    case HIGH:
      echo_death_time = 0;
      echo_hit_time = micros();
      break;
      
    case LOW:
      echo_death_time = micros();
      distance = (echo_death_time - echo_hit_time)/58.2;
      break;
  }
}

void setup() {
  echo_hit_time = echo_death_time = 0;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_OK, OUTPUT);
  pinMode(led_CLOSE, OUTPUT);
  attachInterrupt(0, echo_int, CHANGE);
}

void loop() {
  // Trigger sonar 
  digitalWrite(trigger, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
 
  if (distance > 200) {
    digitalWrite(led_CLOSE, LOW);     
    digitalWrite(led_OK, HIGH);  
  } else if (distance < 100 && distance > 50) {
    digitalWrite(led_CLOSE, HIGH);
    digitalWrite(led_OK, HIGH);
  } else if (distance < 50) {
    digitalWrite(led_CLOSE, HIGH);
    digitalWrite(led_OK, LOW);
  } /*else {
    digitalWrite(led_CLOSE, LOW);
    digitalWrite(led_OK, LOW);
  }*/
   
  delay(50);
}

