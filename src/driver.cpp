#include <iostream>
#include <cmath>

#include "grapher.h"

using namespace std;
using namespace glot;

list<point*> points;
color c(1.0, 0.0, 0.0, 0.5);

double func(double x, double y) {
	return sin(sqrt(x*x + y*y) + (pow(x + 1, 2) + pow(y - 3, 2))/5);
}

double x_function(double x) {
	return cos(x);
	//return x/10;
}

double y_function(double y) {
	return 2 * sin(y);
	//return y/10;
}

double f(double x) {
	//return 3 * sin(exp(x));
	return x * x;
}

void my_click(GLint button, GLint x, GLint y) {
	point* p = new point(grapher::get_x_coord(x), grapher::get_y_coord(y), 0, c);
	grapher::add(*p);
	grapher::redraw();
}

void idle_func() {
	for (int i = 0; i < 100; ++i) {
		//grapher::refresh();
		grapher::redraw();
	}
}

// typedef void (*keyboard_function)(unsigned char key, GLint x, GLint y);
void my_key(unsigned char key, GLint x, GLint y) {
	switch (key) {
		case 'q':
			cout << "Done" << endl;
			exit(1);
			break;
	}
}

int main(int argc, char ** argv) {
	
	grapher::initialize(argc, argv, X_LIN | Y_LIN | AXES_ON | GRID_ON);
	
	color col(1.0, 0, 0);
	/*
	p_curve p(x_function, y_function, col);
	grapher::add(p);
	//*/
	
	/*
	vector v(point(0, 0, 0), point(1, 1, 0), col);
	grapher::add(v);
	//*/
	
	/*
	vector_field vf(x_function, y_function, col, 0.5);
	grapher::add(vf);
	//*/
	
	/*
	contour c(func, col);
	grapher::add(c);
	*/

	/*
	scalar_field sf("sin(sqrt(x * x + y * y + (t * t)))", col);
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			scalar_field * sfp = new scalar_field(argv[i], col);
			grapher::add(*sfp);
		}
	}
	//grapher::add(sf);
	grapher::set_idle_function(idle_func);
	//*/
	
	/*
	gs_contour gsc("sin(sqrt(x * x + y * y))", col);
	grapher::add(gsc);
	//*/
	
	//*
	curve gc("cos(1.0 / x) * x * cos(10 * t)", col);
	grapher::add(gc);
	grapher::set_idle_function(grapher::redraw);
	//*/
	
	/*
	flow gf("sin(x), sin(y) * sin(x)", col);
	grapher::add(gf);
	//*/
	
	/*
	point p(0, 2, 0, NULL);
	line l(1, p, col);
	grapher::add(l);
	//*/
	
	/*
	curve c(f, col);
	grapher::add(c);
	//*/
	
	//grapher::set_click_function(my_click);
	grapher::set_keyboard_function(my_key);
	
	grapher::run();
	
	return 0;
};
