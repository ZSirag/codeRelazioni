#define led1 13
#define led2 12           
#define led3 11
bool stato[3] = {0,0,0};  
#define t1H 250
#define t2H 330      
#define t3H 500
#define t1L 750
#define t2L 400        
#define t3L 500
long tmp1 = 0, tmp2 = 0, tmp3 = 0, mill;
void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  //imposta i pin in OUTPUT
  pinMode(led3, OUTPUT);
}
void loop() {
  mill = millis();
  if ((stato[0] == 1) && (mill-tmp1 >= t1H)){
    tmp1=mill;
    stato[0] = 0;
    digitalWrite(led1, 1);
  }
  else if ((stato[0] == 0) && (mill-tmp1 >= t1L)){
    tmp1=mill;
    stato[0] = 1;
    digitalWrite(led1, 0);
  }
  if ((stato[1]== 1) && (mill-tmp2 >= t2H)){
    tmp2=mill;
    stato[1] = 0;
    digitalWrite(led2, 1);
  }
  else if ((stato[1] == 0) && (mill-tmp2 >= t2L)){
    tmp2=mill;
    stato[1] = 1;
    digitalWrite(led2, 0);
  }
  if ((stato[2]== 1) && (mill-tmp3 >= t3H)){
    tmp3=mill;
    stato[2] = 0;
    digitalWrite(led3, 1);
  }
  else if ((stato[2] == 0) && (mill-tmp3 >= t3L)){
    tmp3=mill;
    stato[2] = 1;
    digitalWrite(led3, 0);
  }

}
