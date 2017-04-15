#ifndef VECTOR_FIELD_CPP
#define VECTOR_FIELD_CPP

#include <cmath>

#include "vector_field.h"

using namespace glot;

double vector_field::x(double t) {
	return x_function.eval(t);
}

double vector_field::y(double t) {
	return y_function.eval(t);
}

void vector_field::dl_gen(const screen& scr) {
	int i, j;
	double x, y;

	for (i = (scr.minx / frequency); i < (scr.maxx / frequency); ++i) {
		for (j = (scr.miny / frequency); j < (scr.maxy / frequency); ++j) {
			x = vector_field::x(i * frequency);
			y = vector_field::y(j * frequency);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
			glTranslated(i * frequency, j * frequency, 0);
			glRotated(-atan2(y, x) * 180.0 / M_PI, 0, 0, 1);
			glScaled(x, x, x);

			glBegin(GL_TRIANGLES);
		
				glVertex3d(-0.1, 0, 0);
				glVertex3d( 0.1, 0, 0);
				glVertex3d(0, 0.5, 0);
			
			glEnd();

			glPopMatrix();
		}
	}
}

#endif