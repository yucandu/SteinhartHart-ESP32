#include "SteinhartHart.h"

/*
 * Constructor
 */
SteinhartHart::SteinhartHart()
{} //End Constructor


/*
 * Constructor
 */
SteinhartHart::SteinhartHart(float resistance1, float resistance2, float resistance3, float temperature1, float temperature2, float temperature3)
{
  _resistance1 = resistance1;
  _resistance2 = resistance2;
  _resistance3 = resistance3;
  _temperature1 = temperature1;
  _temperature2 = temperature2;
  _temperature3 = temperature3;
  calcCoefficients();
} //End Constructor


/*
 * Destructor
 */
SteinhartHart::~SteinhartHart()
{} //End Destructor



/*
 * Calculates the Steinhart-Hart coefficients "a, b, and c".
 */
void SteinhartHart::calcCoefficients()
{
  float L1 = log(_resistance1);
  float L2 = log(_resistance2);
  float L3 = log(_resistance3);
  float Y1 = 1.0 / _temperature1;
  float Y2 = 1.0 / _temperature2;
  float Y3 = 1.0 / _temperature3;
  float y2 = (Y2 - Y1) / (L2 - L1);
  float y3 = (Y3 - Y1) / (L3 - L1);
  _coeffC = ((y3 - y2) / (L3 - L2)) * (pow((L1 + L2 + L3), -1));
  _coeffB = y2 - _coeffC * (pow(L1, 2) + L1 * L2 + pow(L2, 2));
  _coeffA = Y1 - (_coeffB + pow(L1, 2) * _coeffC) * L1;
}


/*
 * Converts resistance to temperature (Kelvin).
 */
float SteinhartHart::resistanceToTemperature(float resistance)
{
  return 1.0 / (_coeffA + _coeffB * log(resistance) + _coeffC * (pow(log(resistance), 3)));
}


/*
 * Converts temperature (Kelvin) to resistance.
 */
float SteinhartHart::temperatureToResistance(float temperature)
{
  float x = 1.0 / (2.0 * _coeffC) * (_coeffA - 1.0 / temperature);
  float y = sqrt(pow(_coeffB / (3.0 * _coeffC), 3) + pow(x, 2));
  return exp(pow(y - x, 1.0 / 3.0) - pow(y + x, 1.0 / 3.0));
}


/*
 *
 */
float SteinhartHart::getCoeffA()
{
  return _coeffA;
}


/*
 *
 */
float SteinhartHart::getCoeffB()
{
  return _coeffB;
}


/*
 *
 */
float SteinhartHart::getCoeffC()
{
  return _coeffC;
}


/*
 *
 */
void SteinhartHart::setCoeffA(float coeffA)
{
  _coeffA = coeffA;
}


/*
 *
 */
void SteinhartHart::setCoeffB(float coeffB)
{
  _coeffB = coeffB;
}


/*
 *
 */
void SteinhartHart::setCoeffC(float coeffC)
{
  _coeffC = coeffC;
}


/*
 *
 */
float SteinhartHart::getResistance1()
{
  return _resistance1;
}


/*
 *
 */
float SteinhartHart::getResistance2()
{
  return _resistance2;
}


/*
 *
 */
float SteinhartHart::getResistance3()
{
  return _resistance3;
}


/*
 *
 */
void SteinhartHart::setResistance1(float resistance1)
{
  _resistance1 = resistance1;
}


/*
 *
 */
void SteinhartHart::setResistance2(float resistance2)
{
  _resistance2 = resistance2;
}


/*
 *
 */
void SteinhartHart::setResistance3(float resistance3)
{
  _resistance3 = resistance3;
}


/*
 *
 */
float SteinhartHart::getTemperature1()
{
  return _temperature1;
}


/*
 *
 */
float SteinhartHart::getTemperature2()
{
  return _temperature2;
}


/*
 *
 */
float SteinhartHart::getTemperature3()
{
  return _temperature3;
}


/*
 *
 */
void SteinhartHart::setTemperature1(float temperature1)
{
  _temperature1 = temperature1;
}


/*
 *
 */
void SteinhartHart::setTemperature2(float temperature2)
{
  _temperature2 = temperature2;
}


/*
 *
 */
void SteinhartHart::setTemperature3(float temperature3)
{
  _temperature3 = temperature3;
}