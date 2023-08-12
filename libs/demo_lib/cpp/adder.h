#pragma once

#include <concepts>

namespace demo_lib {
	template<typename T>
	concept arithmetic = std::integral<T> or std::floating_point<T>;

	template<arithmetic T>
  	T add(T a, T b);

	inline template<arithmetic T>
  	T add(T a, T b) {
		return a + b;
	}
}