#include "SteinhartHart.h"

/*
 * Constructor
 */
SteinhartHart::SteinhartHart()
{} //End Constructor


/*
 * Constructor
 */
SteinhartHart::SteinhartHart(long resistance1, long resistance2, long resistance3, double temperature1, double temperature2, double temperature3)
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
  // Convert to Kelvin
  double T1K = _temperature1;
  double T2K = _temperature2;
  double T3K = _temperature3;

  // Natural log of resistances
  double A1 = log(_resistance1);
  double A2 = log(_resistance2);
  double A3 = log(_resistance3);

  // Spreadsheet-style intermediate values
  double Z = A1 - A2;
  double Y = A1 - A3;
  double X = (1.0 / T1K) - (1.0 / T2K);
  double W = (1.0 / T1K) - (1.0 / T3K);
  double V = pow(A1, 3) - pow(A2, 3);
  double U = pow(A1, 3) - pow(A3, 3);

  double C3a = (X - Z * W / Y) / (V - Z * U / Y);
  double C2a = (X - C3a * V) / Z;
  double C1a = (1.0 / T1K) - C3a * pow(A1, 3) - C2a * A1;

  // Apply scaling
  _coeffC = C3a * 10000000.0;
  _coeffB = C2a * 10000.0;
  _coeffA = C1a * 1000.0;
}

/*
 * Resistance to temperature (Kelvin)
 */
double SteinhartHart::resistanceToTemperature(long resistance)
{
  double logR = log(resistance);
  double invT = (_coeffA / 1000.0) + (_coeffB / 10000.0) * logR + (_coeffC / 10000000.0) * pow(logR, 3);
  return 1.0 / invT;
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
long SteinhartHart::getResistance1()
{
  return _resistance1;
}


/*
 *
 */
long SteinhartHart::getResistance2()
{
  return _resistance2;
}


/*
 *
 */
long SteinhartHart::getResistance3()
{
  return _resistance3;
}


/*
 *
 */
void SteinhartHart::setResistance1(long resistance1)
{
  _resistance1 = resistance1;
  calcCoefficients();
}


/*
 *
 */
void SteinhartHart::setResistance2(long resistance2)
{
  _resistance2 = resistance2;
  calcCoefficients();
}


/*
 *
 */
void SteinhartHart::setResistance3(long resistance3)
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
