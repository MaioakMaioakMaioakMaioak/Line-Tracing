#include <POP32.h>

int L3, L2, L1, R1, R2, R3; 
int RefL3 = 2175, // Analog 0 
    RefL2 = 2230, // Analog 1 
    RefL1 = 2675, // Analog 2 
    RefR1 = 2550, // Analog 3 
    RefR2 = 2230, // Analog 4 
    RefR3 = 2465; // Analog 5 
int LeftSpeed, RightSpeed;
int Error, Integral, Derivative, PreError;
int Kp = 12, Ki = 0, Kd = 1;

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