#include <iostream>
#include "QuickMath/QuickMath.h"

int main()
{
	qmath::quaternion q1(qmath::radians(90.0f), { 0.0f, 0.0f, 1.0f });
	qmath::quaternion q2(0.0f, 0.0f, qmath::sin(qmath::radians(45.0f)), qmath::cos(qmath::radians(45.0f)));

	qmath::vec3 vec(1.0f, 0.0f, 0.0f);

	std::cout << qmath::rotate(vec, q1) << "\n";
	std::cout << qmath::rotate(vec, q2) << "\n";
}
