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