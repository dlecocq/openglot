#ifndef LINE_H
#define LINE_H

#include <OpenGL/gl.h>

#include "primitive.h"
#include "color.h"
#include "point.h"

namespace glot {

	/** \brief a line to plot
	  *
		* \sa curve
		* \sa p_curve
	  */
	class line : public primitive {
	
		public:
			
			/** Color variable
			  *
			  * This is the color the curve is supposed to
			  * take on.
			  */
			color c;
		
			line(double my_m, const point& p, const color& col);
			
			line(double x0, double y0, double x1, double y1, const color& col);
			
			line(const point& p0, const point& p1, const color& col);
		
			/** Evaluate the underlying function at x
			  * \param x - the x value at which to evaluate
			  *
			  * For a given x, it returns the y value of the
			  * function
			  */
			double at(double x);
			
			double zero();
			
			void dl_gen(const screen& scr);
		
		private:
		
			double m, b;
	
	};
	
}

#endif
