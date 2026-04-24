void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void apagarTodo()
{
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);

  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(4,LOW);

  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(3,0);
}

void parpadeo()
{
  for (int i = 0; i < 4; i++)
  {
    analogWrite(11,255);
    analogWrite(10,0);
    analogWrite(9,50);

    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(9,50);

    analogWrite(6,255);
    analogWrite(5,0);
    analogWrite(3,50);

    delay(100);

    apagarTodo();

    delay(100);
  }
}

void loop()
{
  // LED 1 ROJO (analógico)
  analogWrite(11,255);
  analogWrite(10,0);
  analogWrite(9,0);

  delay(1500);
  apagarTodo();
  parpadeo();

  // LED 2 MAGENTA (digital)
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(9,LOW);
  
  delay(1500);
  apagarTodo();
  parpadeo();

  // LED 3 CIAN (analógico tenue)
  analogWrite(6, 0);
  analogWrite(5, 80);
  analogWrite(3, 80);

  delay(1500);
  apagarTodo();
  parpadeo();
}