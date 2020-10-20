//Include Guard:
#ifndef SteinhartHart_h
#define SteinhartHart_h

//Arduino libraries:
#include "Arduino.h"

class SteinhartHart
{
  public:
  	SteinhartHart();
    SteinhartHart(float resistance1, float resistance2, float resistance3, float temperature1, float temperature2, float temperature3);
    ~SteinhartHart();
    void calcCoefficients();
    float resistanceToTemperature(float resistance);
    float temperatureToResistance(float temperature);
    float getCoeffA();
    float getCoeffB();
    float getCoeffC();
    void setCoeffA(float coeffA);
    void setCoeffB(float coeffB);
    void setCoeffC(float coeffC);
    float getResistance1();
    float getResistance2();
    float getResistance3();
    void setResistance1(float resistance1);
    void setResistance2(float resistance2);
    void setResistance3(float resistance3);
    float getTemperature1();
    float getTemperature2();
    float getTemperature3();
    void setTemperature1(float temperature1);
    void setTemperature2(float temperature2);
    void setTemperature3(float temperature3);
  private:
    float _coeffA, _coeffB, _coeffC, _resistance1, _resistance2, _resistance3, _temperature1, _temperature2, _temperature3;
};  //End class SteinhartHart

#endif
