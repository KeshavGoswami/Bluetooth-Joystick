#include<SoftwareSerial.h> SoftwareSerial BTserial(7,8);

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int command;
void setup() {
pinMode(A6,OUTPUT);
//BT.begin(9600); Serial.begin(9600); BTserial.begin(38400); Wire.begin(); mpu.initialize();
if (!mpu.testConnection()) {
while (1);
}
}
void loop() {
digitalWrite(A6,1);
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
//mpu.getRotation(&gx, &gy, &gz);
int state=0;
int vx = map(ax, -16000, 16000,90,-90);
int vy = map(ay, -16000, 16000, 90, -90);
int vz = map(ay, -16000, 16000, 90, -90);

/*Serial.println(vx); Serial.println(vy); Serial.println(vz);*/ if(vx>-90&&vx<-30) state=1;
else if(vx>=-30&&vx<=30)
{
if(vy>-90&&vy<-30)
state=4;
else if(vy>=-30&&vy<=30)
state=0;
else state=3;
}
else state=2;
BTserial.write(state);
Serial.println("\n"); Serial.print(state);
//delay(1000);
} 

