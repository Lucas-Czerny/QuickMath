#pragma once

#include "../dependencies.h"

namespace qmath
{
    class vec2
    {
    public:
        float x = 0.0f, y = 0.0f;

        vec2() = default;
        vec2(const vec2&) = default;

        vec2(float x, float y);

        vec2(float value);

        friend std::ostream& operator<<(std::ostream& os, const vec2& vec);

        float& operator[](int index);
        const float& operator[](int index) const;

        vec2 operator+(const vec2& other);
        vec2 operator-(const vec2& other);
        vec2 operator*(float value);
        vec2 operator/(float value);

        operator array<2>() const;

        qmath::iterator begin() { return qmath::iterator(&x); }
        qmath::iterator end() { return qmath::iterator(&y + 1); }
    };
}

#include "vec2.inl"
