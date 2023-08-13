#include <iostream>
#include <GLFW/glfw3.h>

#include "libs/demo_lib/cpp/adder.h"

int main() {

	float some = demo_lib::add(32.3, 12.2);
	std::cout << "Hello world! : "  << some << std::endl;

	GLFWwindow* window;

	if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

	window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

	while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	// Terminate GLFW
    glfwTerminate();

	return 0;
}