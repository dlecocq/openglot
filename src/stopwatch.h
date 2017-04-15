#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <sys/time.h>
#include <time.h>

class stopwatch {

	public:
	
		stopwatch() : s() {};
	
		void start();
		
		double time();
	
		double stop();

	private:
		timeval s, tmp;
		double t;

};

#endif