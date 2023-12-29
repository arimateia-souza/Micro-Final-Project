unsigned long int avgValue;
int buf[10], temp;
const int SensorPin = A0;
const byte ledR = 10;
const byte ledY = 9;
const byte ledG = 8;
const byte ledB = 7;
   
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    buf[i] = analogRead(SensorPin); 
    delay(10);
  }

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }

  avgValue = 0;
  for (int i = 2; i < 8; i++) 
    avgValue += buf[i];

  float phValue = (float)avgValue * 5.0 / 1024 / 6; 
  phValue = 3.5 * phValue;
  if(phValue <=6){//acido LUZ VERMELHA
    digitalWrite(ledR, HIGH);
 	digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
  }else if(phValue >6 && phValue <=8){//neutro LUZ AMARELA
    digitalWrite(ledR, LOW);
 	digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);  	
  }else if(phValue >=8 && phValue <11){//neutro alcalino LUZ VERDE
    digitalWrite(ledR, LOW);
 	digitalWrite(ledY, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, LOW);  	
  }else if(phValue >=11){// alcalino LUZ AZUL
    digitalWrite(ledR, LOW);
 	digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);  	
  }

  Serial.print("pH: ");
  Serial.print(phValue, 2);
  Serial.println(" ");

}