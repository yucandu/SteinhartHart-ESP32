/*
 * Steinhart-Hart library.
 * Created by Jacob S. Kubisiak on September 22, 2020.
 * Released into the public domain.
 */
//Include Guard:
#ifndef SteinhartHart_h
#define SteinhartHart_h

//Arduino libraries:
#include "Arduino.h"

class SteinhartHart
{
  public:
  	SteinhartHart();
    SteinhartHart(double R1, double R2, double R3, double T1, double T2, double T3);
    ~SteinhartHart();
    void calcCoefficients();
    double resistanceToTemperature(double R);
    double temperatureToResistance(double T);
    double getCoeffA();
    double getCoeffB();
    double getCoeffC();
    void setCoeffA(double coeffA);
    void setCoeffB(double coeffB);
    void setCoeffC(double coeffC);
    double getR1();
    double getR2();
    double getR3();
    void setR1(double R1);
    void setR2(double R2);
    void setR3(double R3);
    double getT1();
    double getT2();
    double getT3();
    void setT1(double T1);
    void setT2(double T2);
    void setT3(double T3);
  private:
    double _coeffA, _coeffB, _coeffC, _R1, _R2, _R3, _T1, _T2, _T3;
};  //End class SteinhartHart

#endif
