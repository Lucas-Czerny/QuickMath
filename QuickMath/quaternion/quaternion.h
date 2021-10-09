#pragma once

#include "../dependencies.h"

#include "../vector/vec3.h"

namespace qmath
{
    class quaternion
    {
    public:
        float x, y, z, w;

        quaternion() = default;
        quaternion(const quaternion&) = default;

        quaternion(float x, float y, float z, float w);
        quaternion(const vec3& vector_part, float real_part);
        quaternion(float angle, const vec3& axis);

        vec3& vector_part() const;
        float real_part() const;

        friend std::ostream& operator<<(std::ostream& os, const quaternion& quaternion);

        quaternion operator*(const quaternion& other);
    };
}

#include "quaternion.inl"
