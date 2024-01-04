#pragma once
#ifdef MATH_LIB_SHARED
#include "math_lib_export.h"
#else
#define MATH_LIB_EXPORT
#endif

namespace math
{
    MATH_LIB_EXPORT double add(double a, double b);
}
