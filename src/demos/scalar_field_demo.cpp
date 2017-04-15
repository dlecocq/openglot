#include <iostream>
#include <vector>
#include <cmath>

#include "../grapher.h"

using namespace std;
using namespace glot;

int main(int argc, char ** argv) {
	
	grapher::initialize(argc, argv, X_LIN | Y_LIN | AXES_ON | GRID_ON);
	
	color col(1.0, 0, 0);
	
	std::vector<scalar_field*> scalar_fields;
	for (int i = 1; i < argc; ++i) {
		scalar_fields.push_back(new scalar_field(argv[i], col));
		grapher::add(*scalar_fields.back());
	}
	
	grapher::set_idle_function(grapher::redraw);
	grapher::run();
	
	std::vector<scalar_field*>::iterator it;
	for (it = scalar_fields.begin(); it != scalar_fields.end(); ++it) {
		delete (*it);
	}
	
	return 0;
};
