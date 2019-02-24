//include nel codice la libreria tasks
#include <Tasks.h>

#define led1 3
#define led2 4 // definisce i pin del led 
#define led3 5

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); // assegna i pin come output
  pinMode(led3, OUTPUT);
  
  //inizia 6 task
  Schedule.begin(6);
  
  //aggunge i teask con il nome, la funzione, l'offset e il ton
  Schedule.addTask("LED1 on", led1on, 0, 500);
  Schedule.addTask("LED1 oFF", led1off, 1, 500);
  Schedule.addTask("LED2 on", led2on, 2, 1000);
  Schedule.addTask("LED2 oFF", led2off, 3, 100);
  Schedule.addTask("LED3 on", led3on, 4, 1500);
  Schedule.addTask("LED3 oFF", led3off, 5, 1500);
  
  //inizia ad eseguire il codice al primo tick 
  Schedule.startTicks(1);
}

//esegue i vari task
void loop(){Schedule.runTasks();}

//funzione dei task
void led1on(){
  digitalWrite(led1, 1);
  Serial.println("LED 1: ACCESO");
}
void led2on(){
  digitalWrite(led2, 1);
  Serial.println("LED 2: ACCESO");
}
void led3on(){
  digitalWrite(led3, 1);
  Serial.println("LED 3: ACCESO");
}
void led1off(){
  digitalWrite(led1, 0);
  Serial.println("LED 1: SPENTO");
}
void led2off(){
  digitalWrite(led2, 0);
  Serial.println("LED 2: SPENTO");
}
void led3off(){
  digitalWrite(led3, 0);
  Serial.println("LED 3: SPENTO");
}
