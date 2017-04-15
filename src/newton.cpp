#include <iostream>
#include <cmath>

#include "grapher.h"

using namespace std;
using namespace glot;

double f(double x) {
	return 4 * pow(x,2) + pow(x,3) - 2 * pow(x,4);
}

color col(1.0, 0.0, 0.0);
list<line*> lines;

void tangent(point p) {
	p.y = f(p.x);
	double df = (f(p.x + 0.1) - f(p.x - 0.1)) / 0.2;
	
	list<line*>::iterator it;
	for (it = lines.begin(); it != lines.end(); ++it) {
		(*it)->c.a *= 0.7;
	}
	
	lines.push_back(new line(df, p, col));
	grapher::add(*(lines.back()));
	grapher::add(p);
	grapher::redraw();
}

void my_click(GLint button, GLint x, GLint y) {
	tangent(grapher::get_point(x, y));
}

void my_key(unsigned char key, GLint x, GLint y) {
	switch (key) {
		case 'q':
			cout << "Done" << endl;
			exit(1);
			break;
		case ' ':
			if (!lines.empty()) {
				line* l = lines.back();
				point p(l->zero(), 0, 0, NULL);
				tangent(p);
			}
			break;
	}
}

int main(int argc, char ** argv) {
	
	grapher::initialize(argc, argv, X_LIN | Y_LIN | AXES_ON | GRID_ON);
	
	curve c(f, col);
	grapher::add(c);
	
	grapher::set_click_function(my_click);
	grapher::set_keyboard_function(my_key);
	
	grapher::run();
	
	return 0;
};
