#pragma once

#include "../dependencies.h"

#include "../utils/trigonometry.h"

#include "../vector/vector.h"
#include "../matrix/matrix.h"

namespace qmath
{
	// TRANSLATE

	mat4 translate(const vec3& translation)
	{
		mat4 transformationMatrix = { {
			{    1.0f,     0.0f,     0.0f,     translation.x    },
			{    0.0f,     1.0f,     0.0f,     translation.y    },
			{    0.0f,     0.0f,     1.0f,     translation.z    },
			{    0.0f,     0.0f,     0.0f,          1.0f        }
		} };

		return transformationMatrix;
	}

	vec4 translate(const vec4& vec, const vec3& translation)
	{
		return translate(translation) * vec;
	}

	// SCALE

	mat4 scale(float scalar, const vec3& axis)
	{
		mat4 transformationMatrix = { {
			{    (scalar - 1) * qmath::square(axis.x) + 1,          (scalar - 1) * axis.x * axis.y,               (scalar - 1) * axis.x * axis.z,          0.0f    },
			{         (scalar - 1) * axis.x * axis.y,          (scalar - 1) * qmath::square(axis.y) + 1,          (scalar - 1) * axis.y * axis.z,          0.0f    },
			{         (scalar - 1) * axis.x * axis.z,               (scalar - 1) * axis.y * axis.z,          (scalar - 1) * qmath::square(axis.z) + 1,     0.0f    },
			{                      0.0f,                                         0.0f,                                         0.0f,                       1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 scale(const vec4& vec, float scalar, const vec3& axis)
	{
		return scale(scalar, axis) * vec;
	}

	mat4 scale(const vec3& scalars)
	{
		mat4 transformationMatrix = { {
			{    scalars.x,       0.0f,          0.0f,        0.0f    },
			{      0.0f,        scalars.y,       0.0f,        0.0f    },
			{      0.0f,          0.0f,        scalars.z,     0.0f    },
			{      0.0f,          0.0f,          0.0f,        1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 scale(const vec4& vec, const vec3& scalars)
	{
		return scale(scalars) * vec;
	}

	// ROTATE - MATRIX

	mat4 rotate(float angle, vec3 axis)
	{
		float cos = qmath::cos(angle),
			  sin = qmath::sin(angle);

		// wtf is this formula
		mat4 transformationMatrix = { {
			{     cos + (1 - cos) * qmath::square(axis.x),       (1 - cos) * axis.x * axis.y - sin * axis.z,     (1 - cos) * axis.x * axis.z + sin * axis.y,     0.0f    },
			{    (1 - cos) * axis.x * axis.y + sin * axis.z,      cos + (1 - cos) * qmath::square(axis.y),       (1 - cos) * axis.y * axis.z - sin * axis.x,     0.0f    },
			{    (1 - cos) * axis.x * axis.z - sin * axis.y,     (1 - cos) * axis.y * axis.z + sin * axis.x,      cos + (1 - cos) * qmath::square(axis.z),       0.0f    },
			{                       0.0f,                                           0.0f,                                           0.0f,                        1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 rotate(const vec4& vec, float angle, vec3 axis)
	{
		return rotate(angle, axis) * vec;
	}

	mat4 rotateX(float angle)
	{
		float cos = qmath::cos(angle),
			  sin = qmath::sin(angle);

		mat4 transformationMatrix = { {
			{    1.0f,     0.0f,     0.0f,     0.0f    },
			{    0.0f,     cos,      -sin,     0.0f    },
			{    0.0f,     sin,      cos,      0.0f    },
			{    0.0f,     0.0f,     0.0f,     1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 rotateX(const vec4& vec, float angle)
	{
		return rotateX(angle) * vec;
	}

	mat4 rotateY(float angle)
	{
		float cos = qmath::cos(angle),
			  sin = qmath::sin(angle);

		mat4 transformationMatrix = { {
			{    cos,      0.0f,     sin,       0.0f    },
			{    0.0f,     1.0f,     0.0f,      0.0f    },
			{    -sin,     0.0f,     cos,       0.0f    },
			{    0.0f,     0.0f,     0.0f,      1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 rotateY(const vec4& vec, float angle)
	{
		return rotateY(angle) * vec;
	}

	mat4 rotateZ(float angle)
	{
		float cos = qmath::cos(angle),
			  sin = qmath::sin(angle);

		mat4 transformationMatrix = { {
			{    cos,      -sin,     0.0f,     0.0f    },
			{    sin,      cos,      0.0f,     0.0f    },
			{    0.0f,     0.0f,     1.0f,     0.0f    },
			{    0.0f,     0.0f,     0.0f,      1.0    }
		} };

		return transformationMatrix;
	}

	vec4 rotateZ(const vec4& vec, float angle)
	{
		return rotateZ(angle) * vec;
	}

	// ROTATE - QUATERNION

	mat4 rotate(const quaternion& q)
	{
		mat4 transformationMatrix = { {
			{    1 - 2.0f * (qmath::square(q.y) - qmath::square(q.z)),                2.0f * (q.x * q.y - q.w * q.z),                           2.0f * (q.x * q.z + q.w * q.y),                0.0f    },
			{               2.0f * (q.x * q.y + q.w * q.z),                1 - 2.0f * (qmath::square(q.x) - qmath::square(q.z)),                2.0f * (q.y * q.z - q.w * q.x),                0.0f    },
			{               2.0f * (q.x * q.z - q.w * q.y),                           2.0f * (q.y * q.z + q.w * q.x),                1 - 2.0f * (qmath::square(q.x) - qmath::square(q.y)),     0.0f    },
			{                            0.0f,                                                     0.0f,                                                     0.0f,                              1.0    }
		} };

		return transformationMatrix;
	}

	vec3 rotate(const vec3& vec, const quaternion& q)
	{
		vec3& vector_part = q.vector_part();
		float vector_length = qmath::dot_product(vector_part, vector_part);

		return ((vec3)vec * (qmath::square(q.w) - vector_length)
			+ vector_part * qmath::dot_product(vec, vector_part) * 2.0f
			+ qmath::cross_product(vector_part, vec) * q.w * 2.0f);
	}

	// SKEW

	mat4 skew(float angle, vec3 baseVectors[2])
	{
		float tan = qmath::tan(angle);
		const vec3& a = qmath::unit_vector(baseVectors[0]);
		const vec3& b = qmath::unit_vector(baseVectors[1]);

		mat4 transformationMatrix = { {
			{    a.x * b.x * tan + 1,       a.x * b.y * tan,         a.x + b.z * tan,        0.0f    },
			{      a.y * b.x * tan,       a.y * b.y * tan + 1,       a.y + b.z * tan,        0.0f    },
			{      a.z * b.x * tan,         a.z * b.y * tan,       a.z * b.z * tan + 1,      0.0f    },
			{           0.0f,                    0.0f,                    0.0f,              1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 skew(const vec4& vec, float angle, vec3 baseVectors[2])
	{
		return skew(angle, baseVectors) * vec;
	}

	mat4 skewX(float angle)
	{
		float tan = qmath::tan(angle);

		mat4 transformationMatrix = { {
			{    1.0f,     tan,      0.0f,     0.0f    },
			{    0.0f,     1.0f,     0.0f,     0.0f    },
			{    0.0f,     0.0f,     0.0f,     0.0f    },
			{    0.0f,     0.0f,     0.0f,     1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 skewX(const vec4& vec, float angle)
	{
		return skewX(angle) * vec;
	}

	mat4 skewY(float angle)
	{
		float tan = qmath::tan(angle);

		mat4 transformationMatrix = { {
			{    1.0f,     0.0f,     0.0f,     0.0f    },
			{    tan,      1.0f,     0.0f,     0.0f    },
			{    0.0f,     0.0f,     1.0f,     0.0f    },
			{    0.0f,     0.0f,     0.0f,     1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 skewY(const vec4& vec, float angle)
	{
		return skewY(angle) * vec;
	}

	mat4 skewZ(float angle)
	{
		float tan = qmath::tan(angle);

		mat4 transformationMatrix = { {
			{    1.0f,     0.0f,     0.0f,     0.0f    },
			{    0.0f,     1.0f,     0.0f,     0.0f    },
			{    0.0f,     tan,      1.0f,     0.0f    },
			{    0.0f,     0.0f,     0.0f,     1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 skewZ(const vec4& vec, float angle)
	{
		return skewZ(angle) * vec;
	}

	// REFLECT

	mat4 reflect(vec3 normal)
	{
		normal = qmath::unit_vector(normal);

		mat4 transformationMatrix = { {
			{    1 - 2 * qmath::square(normal.x),        -2 * normal.x * normal.y,            -2 * normal.x * normal.z,          0.0f    },
			{       -2 * normal.x * normal.y,         1 - 2 * qmath::square(normal.y),        -2 * normal.y * normal.z,          0.0f    },
			{       -2 * normal.x * normal.z,            -2 * normal.y * normal.z,         1 - 2 * qmath::square(normal.z),      0.0f    },
			{                 0.0f,                                0.0f,                                0.0f,                    1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 reflect(const vec4& vec, vec3 normal)
	{
		return reflect(normal) * vec;
	}

	mat4 reflect(vec3 baseVectors[2])
	{
		vec3 normal = qmath::cross_product((vec3&)baseVectors[0], (vec3&)baseVectors[1]);
		return reflect(normal);
	}

	vec4 reflect(const vec4& vec, vec3 baseVectors[2])
	{
		return reflect(baseVectors) * vec;
	}

	mat4 reflectXY()
	{
		mat4 transformationMatrix = { {
			{    1.0f,     0.0f,     0.0f,      0.0f    },
			{    0.0f,     1.0f,     0.0f,      0.0f    },
			{    0.0f,     0.0f,     -1.0f,     0.0f    },
			{    0.0f,     0.0f,     0.0f,      1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 reflectXY(const vec4& vec)
	{
		return { vec.x, vec.y, -vec.z, vec.w };
	}

	mat4 reflectXZ()
	{
		mat4 transformationMatrix = { {
			{    1.0f,     0.0f,      0.0f,     0.0f    },
			{    0.0f,     -1.0f,     0.0f,     0.0f    },
			{    0.0f,     0.0f,      1.0f,     0.0f    },
			{    0.0f,     0.0f,      0.0f,     1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 reflextXZ(const vec4& vec)
	{
		return { vec.x, -vec.y, vec.z, vec.w };
	}

	mat4 reflectYZ()
	{
		mat4 transformationMatrix = { {
			{    -1.0f,     0.0f,     0.0f,     0.0f    },
			{    0.0f,      1.0f,     0.0f,     0.0f    },
			{    0.0f,      0.0f,     1.0f,     0.0f    },
			{    0.0f,      0.0f,     0.0f,     1.0f    }
		} };

		return transformationMatrix;
	}

	vec4 reflextYZ(const vec4& vec)
	{
		return { -vec.x, vec.y, vec.z, vec.w };
	}
}
