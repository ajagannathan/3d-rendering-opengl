#include <iostream>
#include <GL/glew.h>			//Include before GLFW
#include <GLFW/glfw3.h>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/*Initialize GLEW after creating a valid OpenGL context*/
	/*If you encounter a LNK error while calling glew functions,
	try defining GLEW_STATICin the preprocessor declarations
	*/
	if (glewInit() == GLEW_OK)
		std::cout << glGetString(GL_VERSION) << "\n";

	/***************************************/
	/*         Draw a Traingle			   */
	/***************************************/

	/*Generate a buffer*/
	uint32_t buffer;
	glGenBuffers(1, &buffer);

	/*Bind the buffer*/
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	/*Add data to the buffer*/
	float vector_positions[6] = {
		-0.5, -0.5,
		 0.0, 0.5,
		 0.5, -0.5
	};	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vector_positions), vector_positions, GL_STATIC_DRAW);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/*This is legacy OpenGL code to render a triangle*/

		/*glBegin(GL_TRIANGLES);	
		glVertex2d(-0.5, -0.5);
		glVertex2d(0.0, 0.5);
		glVertex2d(0.5, -0.5);
		glEnd();*/


		/*Draw from the buffer*/
		glDrawArrays(GL_TRIANGLES, 0, 3);		// Opengl is a state machine.
												// So when we call glDrawArrays()
												// it uses the buffer it is currently bound to.
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}