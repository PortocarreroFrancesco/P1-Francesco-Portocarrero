#define pinR 11
#define pinB 10
#define pinG 9

void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinG, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(pinR, 0);
  analogWrite(pinB, 0);
  analogWrite(pinG, 0);
  
	for (int R = 0; R < 255; R++)
    {
      analogWrite(pinR, R);
      for (int G = 0; G < 255; G++)
      {
        analogWrite(pinG, G);
       	for(int B = 0; B < 255; B++)
        {
         	 analogWrite(pinB, B);
        }
      }
    }
  delay(1000);
}