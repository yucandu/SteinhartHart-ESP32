//Include Guard:
#ifndef SteinhartHart_h
#define SteinhartHart_h

//Arduino libraries:
#include "Arduino.h"

class SteinhartHart
{
  public:
  	SteinhartHart();
    SteinhartHart(long resistance1, long resistance2, long resistance3, double temperature1, double temperature2, double temperature3);
    ~SteinhartHart();
    void calcCoefficients();
    double resistanceToTemperature(long resistance);
    double temperatureToResistance(double temperature);
    
    // Helper functions for temperature conversion
    double celsiusToKelvin(double celsius);
    double kelvinToCelsius(double kelvin);
    
    // Coefficient getters and setters
    double getCoeffA();
    double getCoeffB();
    double getCoeffC();
    void setCoeffA(double coeffA);
    void setCoeffB(double coeffB);
    void setCoeffC(double coeffC);
    
    // Resistance getters and setters
    long getResistance1();
    long getResistance2();
    long getResistance3();
    void setResistance1(long resistance1);
    void setResistance2(long resistance2);
    void setResistance3(long resistance3);
    
    // Temperature getters and setters
    double getTemperature1();
    double getTemperature2();
    double getTemperature3();
    void setTemperature1(double temperature1);
    void setTemperature2(double temperature2);
    void setTemperature3(double temperature3);
    
  private:
    long _resistance1, _resistance2, _resistance3;
	double _temperature1, _temperature2, _temperature3;
	double _coeffA, _coeffB, _coeffC;
};  //End class SteinhartHart

#endif
