#define pinR 4
#define pinG 2
#define pinBUZZER 7
#define pinPIR A0


void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinBUZZER, OUTPUT);
}

void loop()
{
  digitalWrite(pinR, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinBUZZER, LOW);
  
  int resultadoPIR = digitalRead(pinPIR);
  if(resultadoPIR == LOW)
  {
    digitalWrite(pinG, HIGH);
  }
  else if (resultadoPIR == HIGH)
  {
    digitalWrite(pinR, HIGH);
    digitalWrite(pinBUZZER, HIGH);
  }
}