#pragma once

#include "../dependencies.h"

#include "../vector/vector.h"

namespace qmath
{
	int size(const vec2& vec) { return 2; }
	int size(const vec3& vec) { return 3; }
	int size(const vec4& vec) { return 4; }

	template <typename vector>
	float magnitude(const vector& vec);
	
	template <typename vector>
	vector unit_vector(vector& vec);

	template <typename vector>
	std::string string(const vector& vec);

	template <typename vector>
	float dot_product(const vector& vec1, const vector& vec2);
	
	vec3 cross_product(const vec3& vec1, const vec3& vec2);
}

#include "vector.inl"