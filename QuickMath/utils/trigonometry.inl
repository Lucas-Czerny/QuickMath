#pragma once

#include "../dependencies.h"

namespace qmath
{
	float degrees(float radians)
	{
		return radians * 180.0f / qmath::pi;
	}

	float radians(float degrees)
	{
		return degrees * qmath::pi / 180.0f;
	}

	float sin(float radians)
	{
		return std::sinf(radians);
	}

	float cos(float radians)
	{
		return std::cosf(radians);
	}

	float tan(float radians)
	{
		return std::tanf(radians);
	}
}