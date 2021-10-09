#include "../dependencies.h"

namespace qmath
{
    vec4::vec4(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {}

    vec4::vec4(const vec2& vector2, float z /* = 0.0f */, float w /* = 0.0f */)
        : x(vector2.x), y(vector2.y), z(z), w(w) {}

    vec4::vec4(const vec3& vector3, float w /* = 0.0f */)
        : x(vector3.x), y(vector3.y), z(vector3.z), w(w) {}

    vec4::vec4(float value)
        : x(value), y(value), z(value), w(value) {}

    float& vec4::operator[](int index)
    {
        return (&x)[index];
    }

    const float& vec4::operator[](int index) const
    {
        return (&x)[index];
    }

    vec4 vec4::operator+(const vec4& other)
    {
        vec4 result(*this);
        
        for (int i = 0; i < 4; i++)
        {
            result[i] += other[i];
        }

        return result;
    }

    vec4 vec4::operator-(const vec4& other)
    {
        vec4 result(*this);

        for (int i = 0; i < 4; i++)
        {
            result[i] -= other[i];
        }

        return result;
    }

    vec4 vec4::operator*(float value)
    {
        vec4 result(*this);

        for (int i = 0; i < 4; i++)
        {
            result[i] *= value;
        }

        return result;
    }

    vec4 vec4::operator/(float value)
    {
        vec4 result(*this);

        for (int i = 0; i < 4; i++)
        {
            result[i] /= value;
        }

        return result;
    }

    vec4::operator array<4>() const
    {
        return { x, y, z, w };
    }
}
