#include "../dependencies.h"

namespace qmath
{
    vec2::vec2(float x, float y)
        : x(x), y(y) {}

    vec2::vec2(float value)
        : x(value), y(value) {}

    float& vec2::operator[](int index)
    {
        return (&x)[index];
    }

    const float& vec2::operator[](int index) const
    {
        return (&x)[index];
    }

    vec2 vec2::operator+(const vec2& other)
    {
        vec2 result(*this);

        for (int i = 0; i < 2; i++)
        {
            result[i] += other[i];
        }

        return result;
    }

    vec2 vec2::operator-(const vec2& other)
    {
        vec2 result(*this);

        for (int i = 0; i < 2; i++)
        {
            result[i] -= other[i];
        }

        return result;
    }

    vec2 vec2::operator*(float value)
    {
        vec2 result(*this);

        for (int i = 0; i < 2; i++)
        {
            result[i] *= value;
        }

        return result;
    }

    vec2 vec2::operator/(float value)
    {
        vec2 result(*this);

        for (int i = 0; i < 2; i++)
        {
            result[i] /= value;
        }

        return result;
    }

    vec2::operator array<2>() const
    {
        return { x, y };
    }
}
