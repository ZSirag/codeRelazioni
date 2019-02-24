#include <Tasks.h>
#define led1 3
#define led2 4
#define led3 5
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Schedule.begin(6);
  Schedule.addTask("LED1 on", led1on, 0, 500);
  Schedule.addTask("LED1 oFF", led1off, 1, 500);
  Schedule.addTask("LED2 on", led2on, 2, 1000);
  Schedule.addTask("LED2 oFF", led2off, 3, 100);
  Schedule.addTask("LED3 on", led3on, 4, 1500);
  Schedule.addTask("LED3 oFF", led3off, 5, 1500);
  Schedule.startTicks(1);
}
void loop(){Schedule.runTasks();}
void led1on(){
  digitalWrite(led1, 1);
  Serial.println("zz");
}
void led2on(){
  digitalWrite(led2, 1);
  Serial.println("zz");
}
void led3on(){
  digitalWrite(led3, 1);
  Serial.println("zz");
}
void led1off(){
  digitalWrite(led1, 0);
  Serial.println("zz");
}
void led2off(){
  digitalWrite(led2, 0);
  Serial.println("zz");
}
void led3off(){
  digitalWrite(led3, 0);
  Serial.println("zz");
}
