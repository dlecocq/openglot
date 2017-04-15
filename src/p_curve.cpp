#ifndef P_CURVE_CPP
#define P_CURVE_CPP

#include <OpenGL/gl.h>

#include "p_curve.h"

using namespace glot;

double p_curve::x(double t) {
	return x_function.eval(t);
}

double p_curve::y(double t) {
	return y_function.eval(t);
}

void p_curve::dl_gen(const screen& scr) {
	glBegin(GL_LINE_STRIP);
		double t = 0;
		double h = 1.0 / scr.width;
		double tn = t + h;
		glVertex3d(x(t), y(t), 0);
		for (int i = 0; i < scr.width; ++i) {
			t = tn;
			tn += h;
			glVertex3d(x(t), y(t), 0);
		}
	glEnd();
}

#endif