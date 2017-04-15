#include <iostream>
#include <vector>
#include <cmath>

#include "../grapher.h"

using namespace std;
using namespace glot;

int main(int argc, char ** argv) {
	
	grapher::initialize(argc, argv, X_LIN | Y_LIN | AXES_ON | GRID_ON);
	
	color col(1.0, 0, 0);
	
	std::vector<curve*> curves;
	for (int i = 1; i < argc; ++i) {
		curves.push_back(new curve(argv[i], col));
		grapher::add(*curves.back());
	}
	
	grapher::run();
	
	std::vector<curve*>::iterator it;
	for (it = curves.begin(); it != curves.end(); ++it) {
		delete (*it);
	}
	
	return 0;
};
