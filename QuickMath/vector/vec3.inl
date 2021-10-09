#include "../dependencies.h"

#include "vec4.h"

namespace qmath
{
    vec3::vec3(float x, float y, float z)
        : x(x), y(y), z(z) {}

    vec3::vec3(const vec2& vector2, float z /* = 0.0f */)
        : x(vector2.x), y(vector2.y), z(z) {}

    vec3::vec3(float value)
        : x(value), y(value), z(value) {}

    float& vec3::operator[](int index)
    {
        return (&x)[index];
    }

    const float& vec3::operator[](int index) const
    {
        return (&x)[index];
    }

    vec3 vec3::operator+(const vec3& other)
    {
        vec3 result(*this);

        for (int i = 0; i < 3; i++)
        {
            result[i] += other[i];
        }

        return result;
    }

    vec3 vec3::operator-(const vec3& other)
    {
        vec3 result(*this);

        for (int i = 0; i < 3; i++)
        {
            result[i] -= other[i];
        }

        return result;
    }

    vec3 vec3::operator*(float value)
    {
        vec3 result(*this);

        for (int i = 0; i < 3; i++)
        {
            result[i] *= value;
        }

        return result;
    }

    vec3 vec3::operator/(float value)
    {
        vec3 result(*this);

        for (int i = 0; i < 3; i++)
        {
            result[i] /= value;
        }

        return result;
    }

    vec3::operator array<3>() const
    {
        return { x, y, z };
    }

    vec3::operator vec4()
    {
        return vec4(*this, 1.0f);
    }
}
