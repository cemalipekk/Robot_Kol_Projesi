#include <Servo.h>

Servo servo1,servo2,servo3,servo4;
int pos1 =0;
int pos2 = 50;
int pos3 = 0;
int pos4 = 0;



void setup() {
 servo1.attach(2);
 servo2.attach(3);
 servo3.attach(6);
 servo4.attach(7);
 Serial1.begin(9600);
}

void loop() {

 if ( Serial1.available()>0){
  char veri = Serial1.read();
  if ( veri=='A' ){
    pos1+=1;
  servo1.write(pos1);
  delay(15);
 }
  if ( veri=='B') {
    pos1-=1;
  servo1.write(pos1);
  delay(15);
 }
  if ( veri=='C'){
    pos2+=1;
  servo2.write(pos2);
  delay(15);
 }
  if ( veri=='D'  ){
    pos2-=1;
  servo2.write(pos2);
  delay(15);
 }
 if ( veri=='E' ){
    pos3+=1;
  servo3.write(pos3);
  delay(15);
 }
  if ( veri=='F' ){
    pos3-=1;
  servo3.write(pos3);
  delay(15);
 }
 if ( veri=='G'){
    pos4+=1;
  servo4.write(pos4);
  delay(15);
 }
  if ( veri=='H'){
    pos4-=1;
  servo4.write(pos4);
  delay(15);
 }
 

 
 
 }
}
