#include <Configs.h>
#include <Controller.h>
#include <ColorSensor.h>
#include <DistanceSensor.h>

int  ball_val;

void setup() 
{
  initialize();
  Sensor_ini();
  distance_ini();
  setupPS2controller();
  
}
void loop() 
{
  tcs.getRawData(&r, &g, &b, &c);
  ball_val = rgb_to_hsv(r, g, b);
  classify(ball_val);
  controller();
  
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  delay(50);
}
