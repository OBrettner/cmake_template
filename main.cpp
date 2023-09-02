#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <iostream>

#include "libs/demo_lib/cpp/adder.h"

int main() {

	float some = demo_lib::add(32.3, 12.2);
	std::cout << "Hello world! : "  << some << std::endl;

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	GLFWwindow* window {glfwCreateWindow(800, 600, "tetst window", nullptr, nullptr)};

	uint32_t extensionCount {};
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::cout << extensionCount << " extension supported \n";

	glm::mat4 matrix;
	glm::vec4 vec;

	auto test {matrix * vec};

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();

	return 0;
}
