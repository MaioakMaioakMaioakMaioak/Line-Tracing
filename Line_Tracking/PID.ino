void CalError()
{
  ConvertAnalog();
  if      (L3 == 1 && L2 == 1 && L1 == 1 && C == 1 && R1 == 1 && R2 == 1 && R3 == 0) Error = 6;  //  1  1  1  1  1  1  0
  else if (L3 == 1 && L2 == 1 && L1 == 1 && C == 1 && R1 == 1 && R2 == 0 && R3 == 0) Error = 5;  //  1  1  1  1  1  0  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1 && C == 1 && R1 == 1 && R2 == 0 && R3 == 1) Error = 4;  //  1  1  1  1  1  0  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1 && C == 1 && R1 == 0 && R2 == 0 && R3 == 1) Error = 3;  //  1  1  1  1  0  0  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1 && C == 1 && R1 == 0 && R2 == 1 && R3 == 1) Error = 2;  //  1  1  1  1  0  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1 && C == 0 && R1 == 0 && R2 == 1 && R3 == 1) Error = 1;  //  1  1  1  0  0  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1 && C == 0 && R1 == 1 && R2 == 1 && R3 == 1) Error = 0;  //  1  1  1  0  1  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 0 && C == 0 && R1 == 1 && R2 == 1 && R3 == 1) Error = -1; //  1  1  0  0  1  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 0 && C == 1 && R1 == 1 && R2 == 1 && R3 == 1) Error = -2; //  1  1  0  1  1  1  1 
  else if (L3 == 1 && L2 == 0 && L1 == 0 && C == 1 && R1 == 1 && R2 == 1 && R3 == 1) Error = -3; //  1  0  0  1  1  1  1 
  else if (L3 == 1 && L2 == 0 && L1 == 1 && C == 1 && R1 == 1 && R2 == 1 && R3 == 1) Error = -4; //  1  0  1  1  1  1  1 
  else if (L3 == 0 && L2 == 0 && L1 == 1 && C == 1 && R1 == 1 && R2 == 1 && R3 == 1) Error = -5; //  0  0  1  1  1  1  1 
  else if (L3 == 0 && L2 == 1 && L1 == 1 && C == 1 && R1 == 1 && R2 == 1 && R3 == 1) Error = -6; //  0  1  1  1  1  1  1 

  else if (L3 == 0 && L2 == 0 && L1 == 0 && C == 0 && R1 == 0 && R2 == 0 && R3 == 0) Error = 100; //  0  0  0  0  0  0  0 
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
  // if (Error == -2) {
  //   LeftOutput  = (LeftSpeed  + Output)+50;
  //   RightOutput = (RightSpeed - Output)-20;
  // } 
  // else {
  //   LeftOutput  = (LeftSpeed  + Output)+30;
  //   RightOutput = (RightSpeed - Output)+10;
  // }

  constrain(LeftOutput,-MaxSpeed,MaxSpeed);
  constrain(RightOutput,-MaxSpeed,MaxSpeed);
      
  motor(,RightOutput);
  motor(,RightOutput);
  motor(,LeftOutput);
  motor(,LeftOutput);
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
