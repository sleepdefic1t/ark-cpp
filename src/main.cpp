#include "utilities/platform.h"

#if (defined PLATFORMIO && !defined UNIT_TEST)

void setup()
{
}

void loop()
{
  delay(1000);
}

#endif
