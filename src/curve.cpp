#ifndef CURVE_CPP
#define CURVE_CPP

#include <iostream>
#include <fstream>

#include "curve.h"

using namespace glot;

void curve::dl_gen(const screen& s) {

	glBegin(GL_LINE_STRIP);
	
		double a = s.minx;
		glVertex3d(a, 0, s.time);
		for (int i = 0; i < s.width; ++i) {
			a = (i + 1) * (s.maxx - s.minx) / s.width + s.minx;
			glVertex3d(a, 0, s.time);
		}
	
	glEnd();
}

string curve::get_geom_shader() {	
	return read_file("shaders/curve.geom.front") + func + read_file("shaders/curve.geom.back");
}

string curve::get_vert_shader() {
	return read_file("shaders/curve.vert");
}

string curve::get_frag_shader() {
	return read_file("shaders/cruve.frag");
}

void curve::gen_shader() {
	
	//f = glCreateShader(GL_FRAGMENT_SHADER);
	v = glCreateShader(GL_VERTEX_SHADER);
	g = glCreateShader(GL_GEOMETRY_SHADER_EXT);
	
	//string frag_src = get_frag_shader();
	string vert_src = get_vert_shader();
	string geom_src = get_geom_shader();
	
	//const GLchar * fs_src = frag_src.c_str();
	const GLchar * vs_src = vert_src.c_str();
	const GLchar * gs_src = geom_src.c_str();	

	//glShaderSource(f, 1, &fs_src, NULL);
	glShaderSource(v, 1, &vs_src, NULL);
	glShaderSource(g, 1, &gs_src, NULL);
	
	//glCompileShader(f);
	glCompileShader(v);
	glCompileShader(g);
	
	p = glCreateProgram();
	
	//glAttachShader(p,f);
	glAttachShader(p,v);
	glAttachShader(p,g);
	
	// It has to be GL_LINES as input, GL_LINE_STRIP as output?
	glProgramParameteriEXT(p, GL_GEOMETRY_INPUT_TYPE_EXT,  GL_LINES);
	//glProgramParameteriEXT(p, GL_GEOMETRY_OUTPUT_TYPE_EXT, GL_POINTS);
	glProgramParameteriEXT(p, GL_GEOMETRY_OUTPUT_TYPE_EXT, GL_LINE_STRIP);
	/*
	GLint temp;
	glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT, &temp);
	//*/
	glProgramParameteriEXT(p, GL_GEOMETRY_VERTICES_OUT_EXT, 40);
	
	glLinkProgram(p);
	
	//cout << "Fragment shader : ";
	//printShaderInfoLog(f);
	
	cout << "Vertex shader : ";
	printShaderInfoLog(v);
	
	cout << "Geometry shader : ";
	printShaderInfoLog(g);
	
	cout << "Program : ";
	printProgramInfoLog(p);
}

#endif
