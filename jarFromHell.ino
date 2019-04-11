int PIN_BUTTON = 0;

int PIN_DATA = 1; //DS
int PIN_LATCH = 2; //ST_CP
int PIN_CLOCK = 3; //SH_CP
int PIN_TONE = 10;

boolean btnFlag = false;
int level = 0;
unsigned long lastPress;
 
void coinSound() {
  tone(PIN_TONE, 987, 35);
  delay(35);
  tone(PIN_TONE, 1318, 140); //220
  delay(245);
}

void setLedPanelLevel(int level) {
  if ((level < 0) || (level > 10))
    return;
  digitalWrite(PIN_LATCH, LOW);
  switch (level) {
    case 0:      
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      break;
    case 1:      
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000001);
      break;
    case 2:      
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000011);
      break;
    case 3:      
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000111);
      break;      
    case 4:      
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00001111);
      break;      
    case 5:      
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00011111);
      break;      
    case 6:   
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00111111);
      break;
    case 7:   
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B01111111);
      break;    
    case 8:   
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000000);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B11111111);
      break;    
    case 9:   
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000001);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B11111111);
      break;    
    case 10:   
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B00000011);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, B11111111);
      break;    
  }
  digitalWrite(PIN_LATCH, HIGH);
}

void setup() {  
  pinMode(PIN_BUTTON, INPUT);
  
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);

  setLedPanelLevel(0);
}

void loop() {
  boolean btn = !digitalRead(PIN_BUTTON);
  if ((btn == true) && (btnFlag == false) && (millis() - lastPress > 50)){
    btnFlag = true;
    lastPress = millis();
    level++;
    if (level > 10)
      level = 0;
    coinSound();
  }
  if ((btn == false) && btnFlag == true){
    btnFlag = false;
  }
  setLedPanelLevel(level);
}
