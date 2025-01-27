#include <POP32.h>
#include <U8g2lib.h>  // ใช้ U8g2
#include <Wire.h>     // จำเป็นสำหรับการสื่อสาร I2C

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int FL, C, FR, BL, BR;
int RefFL = 1900,
    RefC  = 2435,
    RefFR = 2090,
    RefBL = 2080,
    RefBR = 2135;
int LeftSpeed, RightSpeed;
int Error, Integral, Derivative, PreError;
int Kp = 15, Ki = 0, Kd = 3;

const int ZX_SWITCH_PIN = 22;  // ต่อสวิตช์กับ D22 (TX-22-PB6)

void setup() {
  pinMode(ZX_SWITCH_PIN, INPUT_PULLUP);  // เปิดโหมด Pull-up สำหรับสวิตช์
  u8g2.begin();  // เริ่มต้นจอ OLED
  u8g2.setFlipMode(1);  // กลับหัวข้อความ (0 = ปกติ, 1 = กลับหัว)
}

void loop() {
  if (digitalRead(ZX_SWITCH_PIN) == LOW) {
    while (digitalRead(ZX_SWITCH_PIN) == LOW);
    TrackJC(60, 1000);
    MotorStop();
  }
  ShowData();
}
