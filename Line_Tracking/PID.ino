void CalError()
{
  ConvertAnalog(false);
  if      (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 0) Error = 5;  //  1  1  1  1  1  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 0 && R3 == 0) Error = 4;  //  1  1  1  1  0  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 0 && R3 == 1) Error = 3;  //  1  1  1  1  0  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 0 && R2 == 0 && R3 == 1) Error = 2;  //  1  1  1  0  0  1
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 0 && R2 == 1 && R3 == 1) Error = 1;  //  1  1  1  0  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 0  && R1 == 0 && R2 == 1 && R3 == 1) Error = 0;  //  1  1  0  0  1  1  mid
  else if (L3 == 1 && L2 == 1 && L1 == 0  && R1 == 1 && R2 == 1 && R3 == 1) Error = -1; //  1  1  0  1  1  1
  else if (L3 == 1 && L2 == 0 && L1 == 0  && R1 == 1 && R2 == 1 && R3 == 1) Error = -2; //  1  0  0  1  1  1
  else if (L3 == 1 && L2 == 0 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -3; //  1  0  1  1  1  1 
  else if (L3 == 0 && L2 == 0 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -4; //  0  0  1  1  1  1
  else if (L3 == 0 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -5; //  0  1  1  1  1  1 

  else if (L3 == 0 && L2 == 0 && L1 == 0 && R1 == 0 && R2 == 0 && R3 == 0) Error = 100; //  0  0  0  0  0  0  0 
  else if (L3 == 0 && L2 == 0 && L1 == 0) Error = 101;     // 0 0 0 ? ? ? ?
  else if (R1 == 0 && R2 == 0 && R3 == 0) Error = 102;     // ? ? ? ? 0 0 0
}

void TrackPID(int MotorSpeed)
{
  int Output,LeftOutput, RightOutput, MaxSpeed = MotorSpeed;

  TuneMotor(MotorSpeed); 
  Integral += Error;    // Integral = Integral + Error; 
  Derivative = Error - PreError;
  Output = (Kp * Error) + (Ki * Integral) + (Kd * Derivative);
  LeftOutput  = (LeftSpeed  + Output);
  RightOutput = (RightSpeed - Output);

  constrain(LeftOutput,-MaxSpeed,MaxSpeed);
  constrain(RightOutput,-MaxSpeed,MaxSpeed);
      
  motor(1,RightOutput);
  motor(3,RightOutput);
  motor(2,LeftOutput);
  motor(4,LeftOutput);
  // motor(2,-LeftOutput);
  // motor(4,-LeftOutput);
  
  PreError = Error;
}

void TrackJC(int MotorSpeed, int Time) // เดินเช็คแยก
{
  int Error = 0;
  int PreError = 0; 
  while(Error < 100)
  {
    TrackPID(MotorSpeed);
    CalError();
  }
  Forward(MotorSpeed,Time);
}