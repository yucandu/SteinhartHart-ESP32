#include "SteinhartHart.h"

/*
 * Constructor
 */
SteinhartHart::SteinhartHart()
{} //End Constructor


/*
 * Constructor
 */
SteinhartHart::SteinhartHart(double resistance1, double resistance2, double resistance3, double temperature1, double temperature2, double temperature3)
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
 * Assumes input temperatures are in Kelvin.
 * For Celsius input, add 273.15 to convert to Kelvin.
 */
void SteinhartHart::calcCoefficients()
{
  // Calculate natural logarithms of resistances
  double L1 = log(_resistance1);
  double L2 = log(_resistance2);
  double L3 = log(_resistance3);
  
  // Calculate reciprocals of temperatures (assuming Kelvin)
  double Y1 = 1.0 / _temperature1;
  double Y2 = 1.0 / _temperature2;
  double Y3 = 1.0 / _temperature3;
  
  // Calculate intermediate values
  double gamma2 = (Y2 - Y1) / (L2 - L1);
  double gamma3 = (Y3 - Y1) / (L3 - L1);
  
  // Calculate coefficients using correct Steinhart-Hart solution
  _coeffC = (gamma3 - gamma2) / (L3 - L2);
  _coeffB = gamma2 - _coeffC * (L1 * L1 + L1 * L2 + L2 * L2);
  _coeffA = Y1 - (_coeffB + _coeffC * L1 * L1) * L1;
}


/*
 * Converts resistance to temperature (Kelvin).
 */
double SteinhartHart::resistanceToTemperature(double resistance)
{
  double logR = log(resistance);
  return 1.0 / (_coeffA + _coeffB * logR + _coeffC * logR * logR * logR);
}


/*
 * Converts temperature (Kelvin) to resistance.
 * Uses iterative Newton-Raphson method for better accuracy.
 */
double SteinhartHart::temperatureToResistance(double temperature)
{
  // Initial guess - use middle calibration point as starting point
  double resistance = _resistance2;
  double targetInvT = 1.0 / temperature;
  
  // Newton-Raphson iteration
  for (int i = 0; i < 10; i++) {
    double logR = log(resistance);
    double logR3 = logR * logR * logR;
    
    // Calculate f(R) = A + B*ln(R) + C*ln(R)^3 - 1/T
    double f = _coeffA + _coeffB * logR + _coeffC * logR3 - targetInvT;
    
    // Calculate f'(R) = (B + 3*C*ln(R)^2) / R
    double df_dR = (_coeffB + 3.0 * _coeffC * logR * logR) / resistance;
    
    // Newton-Raphson update: R_new = R_old - f(R)/f'(R)
    double newResistance = resistance - f / df_dR;
    
    // Check for convergence
    if (abs(newResistance - resistance) < 0.001) {
      return newResistance;
    }
    
    resistance = newResistance;
    
    // Ensure resistance stays positive
    if (resistance <= 0) {
      resistance = 1.0;
    }
  }
  
  return resistance;
}


/*
 * Helper function to convert Celsius to Kelvin
 */
double SteinhartHart::celsiusToKelvin(double celsius)
{
  return celsius + 273.15;
}


/*
 * Helper function to convert Kelvin to Celsius
 */
double SteinhartHart::kelvinToCelsius(double kelvin)
{
  return kelvin - 273.15;
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
double SteinhartHart::getResistance1()
{
  return _resistance1;
}


/*
 *
 */
double SteinhartHart::getResistance2()
{
  return _resistance2;
}


/*
 *
 */
double SteinhartHart::getResistance3()
{
  return _resistance3;
}


/*
 *
 */
void SteinhartHart::setResistance1(double resistance1)
{
  _resistance1 = resistance1;
  calcCoefficients();
}


/*
 *
 */
void SteinhartHart::setResistance2(double resistance2)
{
  _resistance2 = resistance2;
  calcCoefficients();
}


/*
 *
 */
void SteinhartHart::setResistance3(double resistance3)
{
  _resistance3 = resistance3;
  calcCoefficients();
}


/*
 *
 */
double SteinhartHart::getTemperature1()
{
  return _temperature1;
}


/*
 *
 */
double SteinhartHart::getTemperature2()
{
  return _temperature2;
}


/*
 *
 */
double SteinhartHart::getTemperature3()
{
  return _temperature3;
}


/*
 *
 */
void SteinhartHart::setTemperature1(double temperature1)
{
  _temperature1 = temperature1;
  calcCoefficients();
}


/*
 *
 */
void SteinhartHart::setTemperature2(double temperature2)
{
  _temperature2 = temperature2;
  calcCoefficients();
}


/*
 *
 */
void SteinhartHart::setTemperature3(double temperature3)
{
  _temperature3 = temperature3;
  calcCoefficients();
}
