#ifndef LINE_CPP
#define LINE_CPP

#include <cassert>

#include "line.h"

using namespace glot;

line::line(double my_m, const point& p, const color& col) : primitive(col), m(my_m) {
	b = p.y - my_m * p.x;
}

line::line(double x0, double y0, double x1, double y1, const color& col) : primitive(col) {
	// Assert that x0 != x1
	assert(x0 != x1);
	m = (y0 - y1) / (x0 - x1);
	b = y1 - m * x1;
}

line::line(const point& p0, const point& p1, const color& col) : primitive(col) {
	assert(p0.x != p1.x);
	m = (p0.y - p1.y) / (p0.x - p1.x);
	b = p1.y - m * p1.x;
}

double line::at(double x) {
	return m * x + b;
}

double line::zero() {
	return b / m;
}

void line::dl_gen(const screen& scr) {
	glBegin(GL_LINE_STRIP);

		glVertex3d(scr.minx, at(scr.minx), 0);
		glVertex3d(scr.maxx, at(scr.maxx), 0);
	
	glEnd();
}

#endif