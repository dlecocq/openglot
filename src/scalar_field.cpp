#ifndef SCALAR_FIELD_CPP
#define SCALAR_FIELD_CPP

#include <iostream>
#include <fstream>

#include "scalar_field.h"

using namespace glot;

void scalar_field::dl_gen(const screen& s) {
	//glUseProgram(p);
	glBegin(GL_QUADS);
		glTexCoord3f(s.minx, s.miny, s.time);
			glVertex3f(s.minx, s.miny, 0);
		glTexCoord3f(s.minx, s.maxy, s.time);
			glVertex3f(s.minx, s.maxy, 0);
		glTexCoord3f(s.maxx, s.maxy, s.time);
			glVertex3f(s.maxx, s.maxy, 0);
		glTexCoord3f(s.maxx, s.miny, s.time);
			glVertex3f(s.maxx, s.miny, 0);
	glEnd();
	//glUseProgram(0);
	t += 0.1;
}

void scalar_field::gen_shader() {
	
	//string program = read_file("shaders/mandelbrot.frag");
	string program = read_file("shaders/scalar.frag.front") + f + read_file("shaders/scalar.frag.back");
	
	std::cout << program << std::endl;

	GLhandleARB frag = glCreateShader(GL_FRAGMENT_SHADER);

	const GLchar * ff = program.c_str();

	glShaderSource(frag, 1, &ff, NULL);

	glCompileShader(frag);

	p = glCreateProgram();
	
	glAttachShader(p,frag);
	
	glLinkProgram(p);
}

#endif
