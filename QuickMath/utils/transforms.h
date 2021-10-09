#pragma once

#include "../dependencies.h"

#include "../vector/vector.h"
#include "../matrix/matrix.h"
#include "../quaternion/quaternion.h"

namespace qmath
{
	// TRANSLATE

	mat4 translate(const vec3& translation);
	vec4 translate(const vec4& vec, const vec3& translation);

	// SCALE

	mat4 scale(float scalar, const vec3& axis);
	vec4 scale(const vec4& vec, float scalar, const vec3& axis);

	mat4 scale(const vec3& scalars);
	vec4 scale(const vec4& vec, const vec3& scalars);

	// ROTATE - MATRIX

	mat4 rotate(float angle, vec3 axis);
	vec4 rotate(const vec4& vec, float angle, vec3 axis);

	mat4 rotateX(float angle);
	vec4 rotateX(const vec4& vec, float angle);

	mat4 rotateY(float angle);
	vec4 rotateY(const vec4& vec, float angle);

	mat4 rotateZ(float angle);
	vec4 rotateZ(const vec4& vec, float angle);

	// ROTATE - QUATERNION

	mat4 rotate(const quaternion& quaternion);
	vec3 rotate(const vec3& vec, const quaternion& quaternion);

	// SKEW

	mat4 skew(float angle, vec3 baseVectors[2]);
	vec4 skew(const vec4& vec, float angle, vec3 baseVectors[2]);

	mat4 skewX(float angle);
	vec4 skewX(const vec4& vec, float angle);

	mat4 skewY(float angle);
	vec4 skewY(const vec4& vec, float angle);

	mat4 skewZ(float angle);
	vec4 skewZ(const vec4& vec, float angle);

	// REFLECT

	mat4 reflect(vec3 normal);
	vec4 reflect(const vec4& vec, vec3 normal);

	mat4 reflect(vec3 baseVectors[2]);
	vec4 reflect(const vec4& vec, vec3 baseVectors[2]);

	mat4 reflectXY();
	vec4 reflectXY(const vec4& vec);

	mat4 reflectXZ();
	vec4 reflextXZ(const vec4& vec);

	mat4 reflectYZ();
	vec4 reflextYZ(const vec4& vec);
}

#include "transforms.inl"
