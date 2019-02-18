 class imposta {
    byte this_pin;
    long this_ton, this_toff;   
    bool stato;
    unsigned long pMill;
  public:
    imposta(byte pin,long ton, long toff){
        this_pin = pin;
        pinMode(this_pin,  OUTPUT);
        this_ton = ton;
        this_toff = toff;
        stato = 0;
        pMill = 0;
    }
    void lampeggia(){
      unsigned long mill = millis();
      if ((stato == 1) && (mill-pMill >= this_ton)){
        pMill = mill;
        stato = 0;
        digitalWrite(this_pin, stato);
      }
      else if((stato == 0) && (mill-pMill >= this_toff)) {
        pMill = mill;
        stato = 1;
        digitalWrite(this_pin, stato);
      }
    }
};
imposta led1(11, 100, 400);
imposta led2(12, 350, 350);
imposta led3(13, 600, 1200);
void setup(){}
void loop(){
  led1.lampeggia();
  led2.lampeggia();
  led3.lampeggia();
}
