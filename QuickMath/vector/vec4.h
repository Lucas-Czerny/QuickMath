#pragma once

#include "../dependencies.h"

#include "vec2.h"
#include "vec3.h"

namespace qmath
{
    class vec4
    {
    public:
        float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;

        vec4() = default;
        vec4(const vec4&) = default;

        vec4(float x, float y, float z, float w);

        vec4(const vec2& vector2, float z = 0.0f, float w = 0.0f);
        vec4(const vec3& vector3, float w = 0.0f);

        vec4(float value);

        friend std::ostream& operator<<(std::ostream& os, const vec4& vec);

        float& operator[](int index);
        const float& operator[](int index) const;

        vec4 operator+(const vec4& other);
        vec4 operator-(const vec4& other);
        vec4 operator*(float value);
        vec4 operator/(float value);

        operator array<4>() const;

        qmath::iterator begin() { return qmath::iterator(&x); }
        qmath::iterator end() { return qmath::iterator(&w + 1); }
    };
}

#include "vec4.inl"
