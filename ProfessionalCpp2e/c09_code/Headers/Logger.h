#ifndef __LOGGER__
#define __LOGGER__

//#include "Preferences.h"
class Preferences;  // forward declaration

class Logger 
{
 public:
  static void setPreferences(const Preferences& inPrefs);
  static void logError(const char* inError);
}; 

#endif // __LOGGER__
