#include <iostream>
#include <vector>
#include <cmath>

#include "../grapher.h"

using namespace std;
using namespace glot;

int main(int argc, char ** argv) {
	
	grapher::initialize(argc, argv, X_LIN | Y_LIN | AXES_ON | GRID_ON);
	
	color col(1.0, 0, 0);
	
	std::vector<flow*> flows;
	for (int i = 1; i < argc; ++i) {
		flows.push_back(new flow(argv[i], col));
		grapher::add(*flows.back());
	}
	
	grapher::set_idle_function(grapher::redraw);
	grapher::run();
	
	std::vector<flow*>::iterator it;
	for (it = flows.begin(); it != flows.end(); ++it) {
		delete (*it);
	}
	
	return 0;
};
