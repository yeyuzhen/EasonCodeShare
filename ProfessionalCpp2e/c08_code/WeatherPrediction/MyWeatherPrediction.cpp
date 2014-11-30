#include <iostream>

#include "MyWeatherPrediction.h"

using namespace std;

void MyWeatherPrediction::setCurrentTempCelsius(int inTemp)
{
  int fahrenheitTemp = convertCelsiusToFahrenheit(inTemp);
  setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius()
{
  int fahrenheitTemp = getTomorrowTempFahrenheit();
  return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult()
{
  cout << "Tomorrow's temperature will be " << 
    getTomorrowTempCelsius() << " degrees Celsius (" <<
    getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;

  cout << "The chance of rain is " << (getChanceOfRain() * 100) << " percent"
       << endl;

  if (getChanceOfRain() > 0.5) {
    cout << "Bring an umbrella!" << endl;
  }
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int inCelsius)
{
  return (int)((9.0/5.0) * (inCelsius + 32));
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int inFahrenheit)
{
  return (int)((5.0/9.0) * (inFahrenheit-32));
}

std::string MyWeatherPrediction::getTemperature() const
{
	return WeatherPrediction::getTemperature() + "°F";
}


int main()
{
  MyWeatherPrediction p;
  p.setCurrentTempCelsius(33);
  p.setPositionOfJupiter(80);
  p.showResult();
  cout << p.getTemperature() << endl;
  return 0;
}
