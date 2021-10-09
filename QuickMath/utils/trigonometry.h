#pragma once

#include "../dependencies.h"

namespace qmath
{
    float degrees(float radians);
    float radians(float degrees);

    float sin(float radians);
    float cos(float radians);
    float tan(float radians);
}

#include "trigonometry.inl"