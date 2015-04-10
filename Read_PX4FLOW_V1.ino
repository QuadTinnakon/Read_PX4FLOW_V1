/*
project_PX4FLOW V1 3 1 Optical Flow Sensor Smart Camera_V1  
by: tinnakon kheowree  
https://sites.google.com/site/tinnakonkheowree/home
tinnakon_za@hotmail.com
tinnakonza@gmail.com
http://quad3d-tin.lnwshop.com/
https://www.facebook.com/tinnakonza

10/04/2558 ,,Read_PX4 ,, Read i2c 400 kHz
support:  
• Arduino Due
• PX4FLOW V1 3 1 Optical Flow Sensor Smart Camera

j1-1 +5V
j1-2 SCL  to pin 21
j1-3 SDA  to pin 20
j1-4 GND
 */

#include "Wire_due32.h"
#include "PX4Flow.h"

PX4Flow sensor = PX4Flow(); 

void setup()
{
  Wire.begin();       
  Serial.begin(115200);  
}

void loop()
{
  sensor.update();
  
  Serial.print("#");
  Serial.print(sensor.gyro_x_rate());Serial.print("\t");
  Serial.print(sensor.gyro_y_rate());Serial.print("\t");
  Serial.print(sensor.pixel_flow_x_sum());Serial.print("\t");
  Serial.print(sensor.pixel_flow_y_sum());Serial.print("\t");
  //Serial.print(sensor.flow_comp_m_x());Serial.print(",");
  //Serial.print(sensor.flow_comp_m_y());Serial.print(",");
  Serial.println(sensor.ground_distance());

  delay(100);
}
