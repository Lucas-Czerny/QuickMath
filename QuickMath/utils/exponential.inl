#include "../dependencies.h"

namespace qmath
{
    float sqrt(float value)
    {
        ASSERT(value >= 0, "You cannot take the square root of a negative number.");

        float guess = value;

        for (int i = 0; i < SQUARE_ROOT_PRECISION; i++)
        {
            guess -= (guess * guess - value) / (2 * guess);
        }

        return guess;
    }

    float sqrt_fast(float value)
    {
        ASSERT(value >= 0, "You cannot take the square root of a negative number.");

        unsigned int i = *(unsigned int*)&value;

        // adjust bias
        i += 127 << 23;
        // approximation of square root
        i >>= 1;

        return *(float*)&i;
    }

    float square(float value)
    {
        return value * value;
    }

    float power(float value, int power)
    {
        float result = value;

        for (int i = 1; i < power; i++)
        {
            result *= value;
        }

        return result;
    }
}
