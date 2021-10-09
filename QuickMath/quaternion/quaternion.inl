#include "../dependencies.h"

#include "../utils/trigonometry.h"

namespace qmath
{
    quaternion::quaternion(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {}

    quaternion::quaternion(const vec3& vector_part, float real_part)
        : x(vector_part.x), y(vector_part.y), z(vector_part.z), w(real_part) {}

    quaternion::quaternion(float angle, const vec3& axis)
    {
        float cos = qmath::cos(angle * 0.5f);
        float sin = qmath::sin(angle * 0.5f);

        x = sin * axis.x;
        y = sin * axis.y;
        z = sin * axis.z;
        w = cos;
    }

    vec3& quaternion::vector_part() const
    {
        return (vec3&)x;
    }

    float quaternion::real_part() const
    {
        return w;
    }

    quaternion quaternion::operator*(const quaternion& other)
    {
        return quaternion(
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w,
            w * other.w - x * other.x - y * other.y - z * other.z
        );
    }
}
