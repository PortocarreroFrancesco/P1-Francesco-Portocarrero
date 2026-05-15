const int pinBoton = 2;
const int pinPotR = A0;
const int pinPotG = A1;
const int pinPotB = A2;

const int ledR = 11;
const int ledG = 9;
const int ledB = 10;

void setup() 
{
  pinMode(pinBoton, INPUT_PULLUP);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  if (digitalRead(pinBoton) == LOW)
  {
    Serial.println("Tiene 10 s para configurar el color del led....");
    delay(10000); 
    
    int valR = map(analogRead(pinPotR), 0, 1023, 0, 255);
    int valG = map(analogRead(pinPotG), 0, 1023, 0, 255);
    int valB = map(analogRead(pinPotB), 0, 1023, 0, 255);
    
    Serial.print("El led esta usando esta configuracion de colores RGB: ( ");
    Serial.print(valR);
    Serial.print("; ");
    Serial.print(valG);
    Serial.print("; ");
    Serial.print(valB);
    Serial.println(" )");
    
    analogWrite(ledR, valR);
    analogWrite(ledG, valG);
    analogWrite(ledB, valB);
    delay(10000);
    
    analogWrite(ledR, 0);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);
    
    delay(500);
  }
}
