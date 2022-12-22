#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50

uint8_t servonum = 0;

int pos1 =0;
int pos2 = 100;
int pos3 = 90;
int pos4 = 90;



void setup() {
 Serial1.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);  
}

void loop() {

 if ( Serial1.available()>0){
  char veri = Serial1.read();
  if ( veri=='A' ){
    pos1+=1;
   pwm.setPWM(0, 0, pulseWidth(pos1));
  delay(15);
 }
  if ( veri=='B') {
    pos1-=1;
  pwm.setPWM(0, 0, pulseWidth(pos1));
  delay(15);
 }
  if ( veri=='C'){
    pos2+=1;
   pwm.setPWM(1, 0, pulseWidth(pos2));
  delay(15);
 }
  if ( veri=='D'  ){
    pos2-=1;
 pwm.setPWM(1, 0, pulseWidth(pos2));
  delay(15);
 }
 if ( veri=='E' ){
    pos3+=1;
  pwm.setPWM(2, 0, pulseWidth(pos3));
  delay(15);
 }
  if ( veri=='F' ){
    pos3-=1;
 pwm.setPWM(2, 0, pulseWidth(pos3));
  delay(15);
 }
 if ( veri=='G'){
    pos4+=1;
   pwm.setPWM(3, 0, pulseWidth(pos4));
  delay(15);
 }
  if ( veri=='H'){
    pos4-=1;
    pwm.setPWM(3, 0, pulseWidth(pos4));
 
  delay(15);
 }
 }
}
 int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial1.println(analog_value);
  return analog_value;
 }
