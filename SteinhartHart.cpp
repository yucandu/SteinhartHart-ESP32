/*
 * Steinhart-Hart library.
 * Created by Jacob S. Kubisiak on September 22, 2020.
 * Released into the public domain.
 */
#include "SteinhartHart.h"

/*
 * Constructor
 */
SteinhartHart::SteinhartHart()
{
  _R1 = 0;
  _R2 = 0;
  _R3 = 0;
  _T1 = 0;
  _T2 = 0;
  _T3 = 0;
  _coeffA = 0;
  _coeffB = 0;
  _coeffC = 0;
} //End Constructor


/*
 * Constructor
 */
SteinhartHart::SteinhartHart(double R1, double R2, double R3, double T1, double T2, double T3)
{
  _R1 = R1;
  _R2 = R2;
  _R3 = R3;
  _T1 = T1;
  _T2 = T2;
  _T3 = T3;
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
  double L1 = log(_R1);
  double L2 = log(_R2);
  double L3 = log(_R3);
  double Y1 = 1.0 / _T1;
  double Y2 = 1.0 / _T2;
  double Y3 = 1.0 / _T3;
  double y2 = (Y2 - Y1) / (L2 - L1);
  double y3 = (Y3 - Y1) / (L3 - L1);
  _coeffC= ((y3 - y2) / (L3 - L2)) * (pow((L1 + L2 + L3), -1));
  _coeffB= y2 - _coeffC* (pow(L1, 2) + L1 * L2 + pow(L2, 2));
  _coeffA= Y1 - (_coeffB + pow(L1, 2) * _coeffC) * L1;
}


/*
 * Converts resistance to temperature (Kelvin).
 */
double SteinhartHart::resistanceToTemperature(double R)
{
  return 1.0 / (_coeffA + _coeffB * log(R) + _coeffC * (pow(log(R), 3)));
} //End resistanceToTemperature


/*
 * Converts temperature (Kelvin) to resistance.
 */
double SteinhartHart::temperatureToResistance(double T)
{
  double x = 1.0 / (2.0 * _coeffC) * (_coeffA - 1.0 / T);
  double y = sqrt(pow(_coeffB / (3.0 * _coeffC), 3) + pow(x, 2));
  return exp(pow(y - x, 1.0 / 3.0) - pow(y + x, 1.0 / 3.0));
}


/*
 *
 */
double SteinhartHart::getCoeffA()
{
  return _coeffA;
}


/*
 *
 */
double SteinhartHart::getCoeffB()
{
  return _coeffB;
}


/*
 *
 */
double SteinhartHart::getCoeffC()
{
  return _coeffC;
}


/*
 *
 */
void SteinhartHart::setCoeffA(double coeffA)
{
  _coeffA = coeffA;
}


/*
 *
 */
void SteinhartHart::setCoeffB(double coeffB)
{
  _coeffB = coeffB;
}


/*
 *
 */
void SteinhartHart::setCoeffC(double coeffC)
{
  _coeffC = coeffC;
}


/*
 *
 */
double SteinhartHart::getR1()
{
  return _R1;
}


/*
 *
 */
double SteinhartHart::getR2()
{
  return _R2;
}


/*
 *
 */
double SteinhartHart::getR3()
{
  return _R3;
}


/*
 *
 */
void SteinhartHart::setR1(double R1)
{
  _R1 = R1;
}


/*
 *
 */
void SteinhartHart::setR2(double R2)
{
  _R2 = R2;
}


/*
 *
 */
void SteinhartHart::setR3(double R3)
{
  _R3 = R3;
}


/*
 *
 */
double SteinhartHart::getT1()
{
  return _T1;
}


/*
 *
 */
double SteinhartHart::getT2()
{
  return _T2;
}


/*
 *
 */
double SteinhartHart::getT3()
{
  return _T3;
}


/*
 *
 */
void SteinhartHart::setT1(double T1)
{
  _T1 = T1;
}


/*
 *
 */
void SteinhartHart::setT2(double T2)
{
  _T2 = T2;
}


/*
 *
 */
void SteinhartHart::setT3(double T3)
{
  _T3 = T3;
}