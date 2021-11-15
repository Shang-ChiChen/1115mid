#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度
int incomingByte;

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 33, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
  pinMode(26, INPUT);
}
int s = 0;
int ps = 0; 
void loop() {
int input = analogRead(26);
  Serial.println(input);
  if(input>10){
    s = 0;
  }else{
    s = 1;
  }
  if (s == 1 && ps == 0) {
        Serial.println("Moving clockwise...");
        myStepper.step(stepsPerRevolution/8);
        delay(50);
        ps = 1;
      }
      else
      if (s == 0 && ps == 1) {
        Serial.println("Moving counterclockwise...");
        myStepper.step(-stepsPerRevolution/8);
        delay(50);
        ps = 0;
      }  
  delay(500);
}
