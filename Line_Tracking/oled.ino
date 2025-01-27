void showname()  //แสดงชื่อ
{
  oled.clear(); //เคลียร์หน้าจอ
  oled.textSize(2); //ขนาดตัวอักษร
  oled.mode(2);
  oled.text(0,0,"YRC001"); //ตัวอักษร
  oled.show();
}

void ShowAnalog()  // LightCheck
{
  ReadAnalog();
  oled.clear(); //เคลียร์หน้าจอ
  oled.textSize(1); //ขนาดตัวอักษร
  oled.mode(2);
  oled.text(0,0,"FL = %d",FL);
  oled.text(1,0,"C  = %d",C);
  oled.text(2,0,"FR = %d",FR);
  oled.text(3,0,"BL = %d",BL);
  oled.text(4,0,"BR = %d",BR);
  oled.show();
}

void ShowData() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  
  // แสดงความเร็วมอเตอร์
  u8g2.setCursor(0, 10);
  u8g2.print("L:");
  u8g2.print(LeftSpeed);
  
  u8g2.setCursor(0, 20);
  u8g2.print("R:");
  u8g2.print(RightSpeed);
  
  // แสดงสถานะเซ็นเซอร์
  u8g2.setCursor(0, 40);
  u8g2.print("FL:");
  u8g2.print(FL);
  
  u8g2.setCursor(40, 40);
  u8g2.print("C:");
  u8g2.print(C);
  
  u8g2.setCursor(80, 40);
  u8g2.print("FR:");
  u8g2.print(FR);
  
  u8g2.sendBuffer();
  delay(100);
}

