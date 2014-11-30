#pragma once

#include "Preferences.h"

class Logger 
{
 public:
  static void setPreferences(const Preferences& inPrefs);
  static void logError(const char* inError);
}; 
