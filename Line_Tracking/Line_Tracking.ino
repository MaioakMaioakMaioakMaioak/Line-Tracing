#include <POP32.h>
#include <U8g2lib.h>  // ใช้ U8g2
#include <Wire.h>     // จำเป็นสำหรับการสื่อสาร I2C

int L3, L2, L1, C, R1, R2, R3; 
int RefL3 = 2474,
    RefL2 = 2402,
    RefL1 = 2230,
    RefC  = 2345,
    RefR1 = 2498,
    RefR2 = 2254,
    RefR3 = 2600; 
int LeftSpeed, RightSpeed;
int Error, Integral, Derivative, PreError;
int Kp = 30, Ki = 0, Kd = 0;

const int ZX_SWITCH_PIN = 22;  // ต่อสวิตช์กับ D22 (TX-22-PB6)

void setup() {
  pinMode(ZX_SWITCH_PIN, INPUT_PULLUP);  // เปิดโหมด Pull-up สำหรับสวิตช์
  // u8g2.begin();  // เริ่มต้นจอ OLED
  // u8g2.setFlipMode(1);  // กลับหัวข้อความ (0 = ปกติ, 1 = กลับหัว)
}

void loop() {
  if (digitalRead(ZX_SWITCH_PIN) == LOW) {
    while (digitalRead(ZX_SWITCH_PIN) == LOW);
    TrackJC(20,3000);
    MotorStop();
  }

}
