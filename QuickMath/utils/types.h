#pragma once

#include "../dependencies.h"

template <typename T, int size>
using basic_array = std::array<T, size>;

template <typename T, int dimension, int size>
using basic_multidimensional_array = basic_array<basic_array<T, size>, dimension>;

template <int size>
using array = basic_array<float, size>;

template <int dimension, int size>
using multidimensional_array = basic_multidimensional_array<float, dimension, size>;

template <int size>
using array_2d = multidimensional_array<2, size>;
using square_array_2d = array_2d<2>;

template <int size>
using array_3d = multidimensional_array<3, size>;
using square_array_3d = array_3d<3>;

template <int size>
using array_4d = multidimensional_array<4, size>;
using square_array_4d = array_4d<4>;