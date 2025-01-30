#include <POP32.h>

// int Ref = 2500; 
// int A0,A2;

void setup() {
  oled.textSize(4);
  oled.textColor(BLACK,WHITE);
  oled.text(4,3,"TheDemonEmperor!");
  oled.show();

}

void loop() {
  // oled.text(0, 0, "L1=%d ", analog(0)); // L1
  // oled.text(2, 0, "R1=%d ", analog(2)); // R1

  // oled.text(3, 0, "L2=%d ", analog(3)); // L2
  // oled.text(4, 0, "R2=%d ", analog(4)); // R2
  // oled.show();
  // delay(100);

  // waitSW_OK();
  // A0 = analog(0);
  // // A2 = analog(2);

  // if(A0<Ref && A2<Ref) {
  //     wheel(50,-50, 0);
  //   }
  // else if(A0>Ref || A2>Ref) {
  //     ao(); 
  //   }
  // } 

  waitSW_OK();
  FR(1500);
  ao();
}

void wheel(int s1, int s2, int s3){
  motor(1, s1); //ขวา
  motor(2, s2); //ซ้าย
  motor(3, s3); //หลัง
}

void Forward(int time){
  wheel(50,-50, 0);
  delay(time);
}

void Backward(int time){
  wheel(-50, 50, 0);
  delay(time);
}

void LeftMove(int time){
  // wheel(0,-50, 0);
  wheel(25,25,-50); 
  delay(time);
}
void RightMove(int time){
  // wheel(0,-50, 0);
  wheel(-25,-25,50); 
  delay(time);
}

/////////////// Important ///////////////// 
void FR(int time){
  wheel(10,-70,70);
  delay(time);
}

void delay(){
  delay(500);
}