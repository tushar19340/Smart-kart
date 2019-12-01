#include<AFMotor.h>
int irleft = A0;
int irright = A1;

AF_DCMotor motorL(4, MOTOR12_1KHZ);

AF_DCMotor motorR(3, MOTOR12_1KHZ);

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(irleft)== LOW && digitalRead(irright) == LOW) 
 {
  
  
  motorR.run(FORWARD);
  motorR.setSpeed(255);
  motorL.run(FORWARD);
  motorL.setSpeed(255); 
  
  Serial.println("straight");
}
if(digitalRead(irleft)==HIGH && digitalRead(irright)==LOW)
{
  motorR.run(FORWARD);
  motorR.setSpeed(155);
  motorL.run(BACKWARD);
  motorL.setSpeed(155);
  Serial.println("left");
}
if(digitalRead(irleft) == LOW && digitalRead(irright) == HIGH)
{
  
  motorL.run(FORWARD);
  motorL.setSpeed(155);
  motorR.run(BACKWARD);
  motorR.setSpeed(155);
  Serial.println("right");
}
if(digitalRead(irleft) == HIGH && digitalRead(irright) == HIGH)
{
  
  motorR.run(BACKWARD);
  motorR.setSpeed(0);
  motorL.run(BACKWARD);
  motorL.setSpeed(0); 
  }
}
