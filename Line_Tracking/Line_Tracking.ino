#include <POP32.h>

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
}

void loop() {
  // ตรวจสอบการกด ZX_SWITCH01
  if (digitalRead(ZX_SWITCH_PIN) == LOW) {  // ถ้ากดสวิตช์ (สัญญาณเป็น LOW)
    while (digitalRead(ZX_SWITCH_PIN) == LOW);  // รอจนกว่าปุ่มจะถูกปล่อย
    // Forward(60,3000);
    // TrackJC(60, 1000);  // เริ่มทำงานติดเส้น
    TrackJC(45,3000);
    MotorStop();        // หยุดหลังทำงานเสร็จ
  }

}
