#pragma once

#include "../dependencies.h"

namespace qmath
{
	template <typename vector>
	float magnitude(const vector& vec)
	{
		float squared_magnitude = 0.0f;

		for (int i = 0; i < qmath::size(vec); i++)
		{
			squared_magnitude += qmath::square(vec[i]);
		}

		return qmath::sqrt(squared_magnitude);
	}

	template <typename vector>
	vector unit_vector(vector& vec)
	{
		float magnitude = qmath::magnitude(vec);
		return vec / magnitude;
	}

	template <typename vector>
	std::string string(const vector& vec)
	{
		std::stringstream output;
		output << "{ " << vec[0];

		for (int i = 1; i < qmath::size(vec); i++)
		{
			output << ", " << vec[i];
		}

		output << " }";

		return output.str();
	}

	std::ostream& operator<<(std::ostream& os, const vec2& vec)
	{
		os << qmath::string(vec);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const vec3& vec)
	{
		os << qmath::string(vec);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const vec4& vec)
	{
		os << qmath::string(vec);
		return os;
	}

	template <typename vector>
	float dot_product(const vector& vec1, const vector& vec2)
	{
		ASSERT(qmath::size(vec1) == qmath::size(vec2));

		float result = 0.0f;

		for (int i = 0; i < qmath::size(vec1); i++)
		{
			result += vec1[i] * vec2[i];
		}

		return result;
	}

	vec3 cross_product(const vec3& vec1, const vec3& vec2)
	{
		ASSERT(qmath::size(vec1) == qmath::size(vec2));

		return { 
			vec1.y * vec2.z - vec1.z * vec2.y,
			vec1.z * vec2.x - vec1.x * vec2.z,
			vec1.x * vec2.y - vec1.y * vec2.x,
		};
	}
}