#include <jni.h>
#include "HelloCpp.h"
#include <iostream>

JNIEXPORT void JNICALL Java_HelloCpp_callCpp(JNIEnv* env, jobject javaobj)
{
  std::cout << "Hello from C++!" << std::endl;
}
