void CalError()
{
  ConvertAnalog();
  if      (FL == 1 && C == 1 && FR == 0) Error =  2;   // 1 1 0  
  else if (FL == 1 && C == 0 && FR == 0) Error =  1;   // 1 0 0
  else if (FL == 1 && C == 0 && FR == 1) Error =  0;   // 1 0 1
  else if (FL == 0 && C == 0 && FR == 1) Error = -1;   // 0 0 1
  else if (FL == 0 && C == 1 && FR == 1) Error = -2;   // 0 1 1

  else if (FL == 0 &&  C == 0 && FR == 0) Error = 100; // 0 0 0 
  else if (FL == 0 &&  C == 0) Error = 101;            // 0 0 ?
  else if (C  == 0 && FR == 0) Error = 102;            // ? 0 0 
}

void TrackPID(int MotorSpeed)
{
  int Output,LeftOutput, RightOutput, MaxSpeed = MotorSpeed;
  CalError();
  TuneMotor(MotorSpeed); 
  Integral += Error;    // Integral = Integral + Error; 
  Derivative = Error - PreError;
  Output = (Kp * Error) + (Ki * Integral) + (Kd * Derivative);
  
  if (Error == -2) {
    LeftOutput  = (LeftSpeed  + Output)+50;
    RightOutput = (RightSpeed - Output)-20;
  } 
  else {
    LeftOutput  = (LeftSpeed  + Output)+30;
    RightOutput = (RightSpeed - Output)+10;
  }

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
  while(Error < 100)
  {
    TrackPID(MotorSpeed);
    CalError();
  }
  Forward(MotorSpeed,Time);
}
