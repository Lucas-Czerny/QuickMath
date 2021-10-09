#pragma once

#include "../dependencies.h"

#include "vec2.h"

namespace qmath
{
    class vec4;

    class vec3
    {
    public:
        float x = 0.0f, y = 0.0f, z = 0.0f;

        vec3() = default;
        vec3(const vec3&) = default;

        vec3(float x, float y, float z);

        vec3(const vec2& vector2, float z = 0.0f);

        vec3(float value);
    
        friend std::ostream& operator<<(std::ostream& os, const vec2& vec);

        float& operator[](int index);
        const float& operator[](int index) const;

        vec3 operator+(const vec3& other);
        vec3 operator-(const vec3& other);
        vec3 operator*(float value);
        vec3 operator/(float value);

        operator array<3>() const;
        operator vec4();

        qmath::iterator begin() { return qmath::iterator(&x); }
        qmath::iterator end() { return qmath::iterator(&z + 1); }
    };
}

#include "vec3.inl"
