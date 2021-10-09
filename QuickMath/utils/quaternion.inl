#pragma once

#include "../dependencies.h"

#include "../vector/vec3.h"

namespace qmath
{
	std::string string(const quaternion& q)
	{
		std::stringstream output;
		output << "{ " << q.w;

		vec3& vector_part = q.vector_part();
		char coefficients[3] = { 'i', 'j', 'k' };

		for (int i = 0; i < 3; i++)
		{
			output << ", " << vector_part[i] << coefficients[i];
		}

		output << " }";

		return output.str();
	}

	std::ostream& operator<<(std::ostream& os, const quaternion& q)
	{
		os << qmath::string(q);
		return os;
	}
}