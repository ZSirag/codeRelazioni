#define k1 0.25
#define k2 0.5
#define k3 0.75
int arr[10], supp[10], x, y;
int calmo[3], media5 = 0, media10 = 0;
int calcolo(byte k){
  y = 0;
  for(byte i = k; i < 10; i++){y = y+arr[i];}
  return y;
}
void stampa(){
  Serial.print(x);
  Serial.print("\t");
  Serial.print(media5);
  Serial.print("\t");
  Serial.print(media10);
  Serial.print("\t");
  Serial.print(calmo[0]);
  Serial.print("\t");
  Serial.print(calmo[1]);
  Serial.print("\t");
  Serial.print(calmo[2]);
  Serial.println(" ");
}
void kalman(){
  calmo[0] = (x*(1-k1))+(calmo[0]*k1);
  calmo[1] = (x*(1-k2))+(calmo[1]*k2);
  calmo[2] = (x*(1-k3))+(calmo[2]*k3);
}
void medie(){
  for(byte i = 1; i < 10; i++){supp[i-1] = arr[i];}
  for(byte i = 0; i < 10; i++){arr[i] = supp[i];}
  arr[9] = x;
  media5 = calcolo(5)/5;
  media10 = calcolo(0)/10;
}
void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  for (byte i = 0; i < 10; i++) {
    arr[i] = 0, supp[i] = 0;
  }
}
void loop() {
  x = analogRead(A0);
  medie();
  kalman();
  stampa();
  delay(200);
}
