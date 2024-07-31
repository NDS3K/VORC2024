#include <Configs.h>

uint16_t r, g, b, c;

double H = 0;
double S = 0;
double V = 0; 

int rgb_to_hsv(double red, double green, double blue)
{
  double R = red/255;
  double G = green/255;
  double B = blue/255;
  double x = max(R,G);
  double y = min(R,G);
  double Cmax = max(x,B);
  double Cmin = min(y,B);
  double denta = Cmax - Cmin;
  V = Cmax;
  if(Cmax == 0)
  {
      S = 0;
  }
  else
  {
      S = (Cmax - Cmin)/Cmax ;
  }
  if(Cmax == Cmin)
  {
      H = 0;
  }
  if(Cmax == R)
  {
    H = 60*((G-B)/denta);
    if(H < 0)
    {
      H += 360;
    }
  }
  else if(Cmax == G)
  {
    H = 60*((B-R)/denta+2);
  }
  else if(Cmax == B)
  {
    H = 60*((R-G)/denta+4);
  }
  if(S == 0 && V == 0)
  {
    Serial.println("black");
    return 1;
  }
  else if(S == 0 && V == 1)
  {
    Serial.println("white");
    return 0;
  }
  else 
  {
    return -1; 
  }
}
