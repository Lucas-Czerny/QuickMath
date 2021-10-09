#pragma once

#include "../dependencies.h"

#include "../utils/types.h"

#include "../vector/vec4.h"

namespace qmath
{
	class mat4x4
	{
	private:
		square_array_4d m_Rows;

	public:
		static mat4x4 identity;

		mat4x4() = default;
		mat4x4(const mat4x4&) = default;

		mat4x4(float value);

		mat4x4(const square_array_4d& rows);
		mat4x4(const std::initializer_list<std::initializer_list<float>>& rows);

		void transpose();

		std::string string() const;
		friend std::ostream& operator<<(std::ostream& os, const mat4x4& mat);

		array<4>& operator[](int index);
		const array<4>& operator[](int index) const;

		mat4x4 operator+(const mat4x4& other);
		mat4x4 operator-(const mat4x4& other);
		mat4x4 operator*(float value);

		mat4x4 operator*(const mat4x4 other);
		vec4 operator*(vec4 other);

		operator square_array_4d() const;
	};

	typedef mat4x4 mat4;
}

#include "mat4x4.inl"