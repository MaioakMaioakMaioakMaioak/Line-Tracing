void TurnLeft()
{
  MotorStop();
  SL(60);       // SpinLeft(int)
  delay(200);
  ConvertAnalog();
  while(FL == 1)
  {
    ConvertAnalog();
  }
  MotorStop();
}

void TurnRight()
{
  MotorStop();
  SR(60);       // SpinRight(int)
  delay(200);
  ConvertAnalog();
  while(FR == 1)
  {
    ConvertAnalog();
  }
  MotorStop();
}

