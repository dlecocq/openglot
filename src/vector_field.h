#ifndef VECTOR_FIELD_H
#define VECTOR_FIELD_H

#include <OpenGL/gl.h>

#include "color.h"
#include "vector.h"
#include "function.h"
#include "primitive.h"

namespace glot {
	
	class vector_field : public primitive {
	
		public:
		
			/** The color of the the point */
			color c;
			
			double frequency;
		
			/** Constructor
			  * \param s - the start point
			  * \param e - the end point
			  * \param col - the color with which to draw
			  */
			//vector(const point& s, const point& e, const color& col) : c(col), start(s), end(e) {};
			
			vector_field(function::double_function x_f, function::double_function y_f, const color& col, double sample = 1.0) : primitive(col), frequency(sample), x_function(x_f), y_function(y_f){};
			
			double x(double t);
			
			double y(double t);
			
			void dl_gen(const screen& scr);
		
		private:
			
			function x_function;
			function y_function;
	
	};

}

#endif
