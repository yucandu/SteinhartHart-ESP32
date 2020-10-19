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
  setResistance1(resistance1);
  setResistance2(resistance2);
  setResistance3(resistance3);
  setTemperature1(temperature1);
  setTemperature2(temperature2);
  setTemperature3(temperature3);
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
  setCoeffC(((y3 - y2) / (L3 - L2)) * (pow((L1 + L2 + L3), -1)));
  setCoeffB(y2 - _coeffC* (pow(L1, 2) + L1 * L2 + pow(L2, 2)));
  setCoeffA(Y1 - (_coeffB + pow(L1, 2) * _coeffC) * L1);
} //End calcCoefficients


/*
 * Converts resistance to temperature (Kelvin).
 */
float SteinhartHart::resistanceToTemperature(float R)
{
  return 1.0 / (_coeffA + _coeffB * log(R) + _coeffC * (pow(log(R), 3)));
} //End resistanceToTemperature


/*
 * Converts temperature (Kelvin) to resistance.
 */
float SteinhartHart::temperatureToResistance(float T)
{
  float x = 1.0 / (2.0 * _coeffC) * (_coeffA - 1.0 / T);
  float y = sqrt(pow(_coeffB / (3.0 * _coeffC), 3) + pow(x, 2));
  return exp(pow(y - x, 1.0 / 3.0) - pow(y + x, 1.0 / 3.0));
} //End temperatureToResistance


/*
 *
 */
float SteinhartHart::getCoeffA()
{
  return _coeffA;
} //End getCoeffA


/*
 *
 */
float SteinhartHart::getCoeffB()
{
  return _coeffB;
} //End getCoeffB


/*
 *
 */
float SteinhartHart::getCoeffC()
{
  return _coeffC;
} //End getCoeffC


/*
 *
 */
void SteinhartHart::setCoeffA(float coeffA)
{
  _coeffA = coeffA;
} //End setCoeffA


/*
 *
 */
void SteinhartHart::setCoeffB(float coeffB)
{
  _coeffB = coeffB;
} //setCoeffB


/*
 *
 */
void SteinhartHart::setCoeffC(float coeffC)
{
  _coeffC = coeffC;
} //setCoeffC


/*
 *
 */
float SteinhartHart::getResistance1()
{
  return _resistance1;
} //End getResistance1


/*
 *
 */
float SteinhartHart::getResistance2()
{
  return _resistance2;
} //End getResistance2


/*
 *
 */
float SteinhartHart::getResistance3()
{
  return _resistance3;
} //End getResistance3


/*
 *
 */
void SteinhartHart::setResistance1(float resistance1)
{
  _resistance1 = resistance1;
} //End setResistance1


/*
 *
 */
void SteinhartHart::setResistance2(float resistance2)
{
  _resistance2 = resistance2;
} //End setResistance2


/*
 *
 */
void SteinhartHart::setResistance3(float resistance3)
{
  _resistance3 = resistance3;
} //End setResistance3


/*
 *
 */
float SteinhartHart::getTemperature1()
{
  return _temperature1;
} //End getTemperature1


/*
 *
 */
float SteinhartHart::getTemperature2()
{
  return _temperature2;
} //End getTemperature2


/*
 *
 */
float SteinhartHart::getTemperature3()
{
  return _temperature3;
} //End getTemperature3


/*
 *
 */
void SteinhartHart::setTemperature1(float temperature1)
{
  _temperature1 = temperature1;
} //End setTemperature1


/*
 *
 */
void SteinhartHart::setTemperature2(float temperature2)
{
  _temperature2 = temperature2;
} //End setTemperature2


/*
 *
 */
void SteinhartHart::setTemperature3(float temperature3)
{
  _temperature3 = temperature3;
} //End setTemperature3