#include "../includes/scop.h"

void error_callback(int error, const char *description)
{
	fprintf(stderr, "Error %d: %s\n", error, description);
}

void fatal_error(char *error)
{
	glfwTerminate();
	fprintf(stderr, "Fatal error:\n%s\n", error);
	exit(EXIT_FAILURE);
}

void leave_scop(t_param *p)
{
	glfwDestroyWindow(p->win);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_param p;
	//GLuint vao;
	GLfloat vertex[9];
	GLuint vbuffer;

	if (argc != 2)
		fatal_error("Please give one file as argument.");

	init_scop(&p);
	//parse_file(argv[1]);

	//glad_glGenVertexArrays(1, &vao);
	//glad_glBindVertexArray(vao);

	// if(gladLoadGL())
	// {
    //     // you need an OpenGL context before loading glad
    //     printf("I did load GL with no context!\n");
    //     exit(-1);
    // }

	//GLEW ?
	//glGenVertexArrays(1, &vao);
	//glBindVertexArray(vao);

	vertex[0] = -1;
	vertex[1] = -1;
	vertex[2] = 0;
	vertex[3] = 1;
	vertex[4] = -1;
	vertex[5] = 0;
	vertex[6] = 0;
	vertex[7] = 1;
	vertex[8] = 0;

	glGenBuffers(1, &vbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	// while (!glfwWindowShouldClose(p.win))
	// {
	// 	glEnableVertexAttribArray(0);
	// 	glBindBuffer(GL_ARRAY_BUFFER, vbuffer);

	// 	glVertexAttribPointer(
	// 		0,
	// 		3,
	// 		GL_FLOAT,
	// 		GL_FALSE,
	// 		0,
	// 		(void*)0
	// 	);

	// 	glDrawArrays(GL_TRIANGLES, 0, 3);
	// 	glDisableVertexAttribArray(0);
	// }

	//ENDTEST
	argv[0] = "ha";
	leave_scop(&p);
	return (0);
}
