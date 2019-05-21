#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <math.h>

#include "include/screen.h"
#include "include/shader.h"
#include "include/texture.h"
#include "include/kbhit.h"

int main(int argc, const char **argv)
{
	InitGraphics();

	GLuint programID = LoadShaders( "shaders/gles/vertex.glsl", "shaders/gles/fragment.glsl" );

	GLuint Texture = loadBMP_custom("flag.bmp");

	GLfloat g_vertex_buffer_data[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
	};

	int time = 0;

	GLint timeID = glGetUniformLocation(programID, "uTime");

	while(!kbhit())
	{

		time++;
		glClear( GL_COLOR_BUFFER_BIT );
		glUseProgram(programID);
		glUniform1f(timeID, time);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);

		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			g_vertex_buffer_data
			);

		glEnableVertexAttribArray ( 0 );

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		updateScreen();
	}

	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
}
