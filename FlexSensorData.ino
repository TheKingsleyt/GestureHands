#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// finger output pins
int flexThumb = A0; //Thumb
int flexIndex = A1; //Index
int flexMiddle = A2; //Middle
int flexRing = A3; //Ring
int flexPinky = A0; //Pinky

int flexThreshold = 600;

void setup(){
  Serial.begin(115200);
  Wire.begin();

  //Initialize MPU6050
  Serial.println("Initizating MPU6050....")
  mpu.Initialize();
  if (mpu.testConnection()){
    Serial.println("MPU6050 connected successfully");
  } else {
    Serial.println("Failed to connect")
  }
}
void loop() {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    // read flex sensor 
    int thumbValue = analogRead(flexThumb);
    int indexValue = analogRead(FlexIndex);
    int middleValue = analogRead(flexMiddle);
    int ringValue = analogRead(flexRing);
    int pinkyValue = analogRead(flexPinky);
