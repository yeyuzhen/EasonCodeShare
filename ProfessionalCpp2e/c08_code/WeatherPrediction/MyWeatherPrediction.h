// MyWeatherPrediction.h

#include "WeatherPrediction.h"

class MyWeatherPrediction : public WeatherPrediction
{
 public:
  virtual void setCurrentTempCelsius(int inTemp);

  virtual int getTomorrowTempCelsius();

  virtual void showResult();

  virtual std::string getTemperature() const;

 protected:
  static int convertCelsiusToFahrenheit(int inCelsius);
  static int convertFahrenheitToCelsius(int inFahrenheit);
}; 
