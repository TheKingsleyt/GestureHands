#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Finger output pins
int flexThumb = A0; // Thumb
int flexIndex = A1; // Index
int flexMiddle = A2; // Middle
int flexRing = A3; // Ring
int flexPinky = A4; // Pinky

int flexThreshold = 600;

void setup(){
  Serial.begin(115200);
  Wire.begin();

  // Initialize MPU6050
  Serial.println("Initializing MPU6050....");
  mpu.initialize();
  if (mpu.testConnection()){
    Serial.println("MPU6050 connected successfully");
  } else {
    Serial.println("Failed to connect");
  }
}

void loop() {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    // Read flex sensor values
    int thumbValue = analogRead(flexThumb);
    int indexValue = analogRead(flexIndex);
    int middleValue = analogRead(flexMiddle);
    int ringValue = analogRead(flexRing);
    int pinkyValue = analogRead(flexPinky);

    // Print sensor values to Serial Monitor for debugging
    Serial.print("Thumb: "); Serial.print(thumbValue);
    Serial.print(" Index: "); Serial.print(indexValue);
    Serial.print(" Middle: "); Serial.print(middleValue);
    Serial.print(" Ring: "); Serial.print(ringValue);
    Serial.print(" Pinky: "); Serial.print(pinkyValue);
    Serial.println();
    
    delay(500); // Adjust delay as needed
}

