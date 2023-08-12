#include <iostream>

#include "libs/demo_lib/cpp/adder.h"


int main() {

	float some = demo_lib::add(32.3, 12.2);
	std::cout << "Hello world! : "  << some << std::endl;

	return 0;
}