#pragma once

#include "../dependencies.h"

namespace qmath
{
    float sqrt(float value);
    float sqrt_fast(float value);

    float square(float value);
    float power(float value, int power);
}

#include "exponential.inl"
