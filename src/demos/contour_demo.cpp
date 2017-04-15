#include <iostream>
#include <vector>
#include <cmath>

#include "../grapher.h"

using namespace std;
using namespace glot;

int main(int argc, char ** argv) {
	
	grapher::initialize(argc, argv, X_LIN | Y_LIN | AXES_ON | GRID_ON);
	
	color col(1.0, 0, 0);
	
	std::vector<contour*> contours;
	for (int i = 1; i < argc; ++i) {
		contours.push_back(new contour(argv[i], col));
		grapher::add(*contours.back());
	}
	
	grapher::run();
	
	std::vector<contour*>::iterator it;
	for (it = contours.begin(); it != contours.end(); ++it) {
		delete (*it);
	}
	
	return 0;
};
