#include <Wire.h>

// MPU6050 I2C address
#define MPU6050_ADDRESS 0x68


int16_t  az, gz;
float yaw;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // Enable the MPU6050
  Wire.endTransmission();

}

void loop() {
  // Read accelerometer data
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x3F);   //ACCEL_ZOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 6, true);
  az = Wire.read() << 8 | Wire.read();

  // Read gyroscope data
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x4);  //GYRO_ZOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 6, true);
  gz = Wire.read() << 8 | Wire.read();

  // Calculate yaw angle using complementary filter
  //complementary filter :: combine the integrated yaw angle (from the gyroscope) with the accelerometer data
  const float Kp = 0.02;    //Proportional Gain
  const float Ki = 0.00003; //Integral Gain
  static float yaw_integral = 0;

  float yaw_rate = (gz - 200) * 0.0175; // Convert from degrees/second to radians/second
  yaw_integral += yaw_rate * 0.01;     // Integrate yaw rate
  yaw += Kp * yaw_rate + Ki * yaw_integral;


  Serial.println(yaw);

  delay(50);
}