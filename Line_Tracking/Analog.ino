void ReadAnalog(){ //อ่านค่าเซนเซอร์ข้างหน้า
  FL = analog(0);     // FrontLeft
  C = analog(1);      // Middle
  FR = analog(2);     // FrontRight
  BL = analog(3);     // BackLeft
  BR = analog(4);     // BackRight
}

void ConvertAnalog(){     // Black = 0, White = 1
  ReadAnalog();
  // ถ้า analog(int) > ค่าเฉลี่ยของ analog(int) --> ananlog(int) = 0 (สีดำ) | ไม่ใช่ --> analog(int) = 1 (สีขาว1)
  if(FL < RefFL) FL=0; else FL = 1;
  if(C  < RefC)  C=0;  else C  = 1;
  if(FR < RefFR) FR=0; else FR = 1;
  if(BL < RefBL) BL=0; else BL = 1;
  if(BR < RefBR) BR=0; else BR = 1;
}