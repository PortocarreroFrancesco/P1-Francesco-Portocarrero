#define pinTemp A0
#define pinLuz A1
#define pinR 11
#define pinG 9
#define pinB 10

float temp = 0;
int valorLuz = 0;
float porcentajeLuz = 0;

void setup() 
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int lecturaTemp = analogRead(pinTemp);
  float volt = lecturaTemp * (5.0 / 1023.0);
  temp = (volt - 0.5) * 100.0;

  valorLuz = analogRead(pinLuz);
  porcentajeLuz = map(valorLuz, 0, 1023, 105, -6);

  Serial.print("El nivel de luz actual es: ");
  Serial.print(porcentajeLuz);
  Serial.print("%");
  Serial.print(" y la temperatura actual: ");
  Serial.print(temp);
  Serial.println(" ºc");

  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);

  if (porcentajeLuz >= 30 && porcentajeLuz <= 70) 
  {
    
	if (temp > 90) 
    {
      analogWrite(pinR, 255);
    } 
    else if (temp < 18) 
    {
      analogWrite(pinB, 255);
    } 
    else 
    {
      analogWrite(pinG, 255);
    }
    
  }

  delay(1000);
}