#ifndef P_CURVE_H
#define P_CURVE_H

#include "primitive.h"
#include "function.h"
#include "color.h"

namespace glot {

	/** \brief p_curve: a parametric curve to plot
	  *
		* This class takes two functions that accept doubles
		* and return a double.  It then samples t in [0,1]
		* and connects the dots with straight lines
		*
		* \sa grapher
		* \sa curve
	  */
	class p_curve : public primitive {
	
		public:
		
			color c;
			
			/** Constructor
			  *	\param x_f - the parametric definition of x
			  * \param y_f - the parametric definition of y
			  *	\param col - the color of the curve
			  * \param t0 - the beginning of the parameterization
			  * \param tf - the end of the parameterization
			  */
			p_curve(const function& x_f, const function& y_f, const color& col, double t0 = 0, double tf = 1) : primitive(col), x_function(x_f), y_function(y_f), tstart(t0), tfinal(tf) {};
			
			/** Constructor
			  * \param x_f - the parametric definition of x
			  * \param y_f - the parametric definition of y
			  *	\param col - the color of the curve
			  * \param t0 - the beginning of the parameterization
			  * \param tf - the end of the parameterization
			  *
			  * Instead of declaring functions and a curve,
			  * we anticipate it being useful to just declare a 
			  * curve with the functions you've already defined
			  */
			p_curve(function::double_function x_f, function::double_function y_f, const color& col, double t0 = 0, double tf = 1) : primitive(col), x_function(x_f), y_function(y_f), tstart(t0), tfinal(tf) {};
			
			double x(double t);
			
			double y(double t);
			
			void dl_gen(const screen& s);
		
		protected:
		
			// This is the function it's meant to plot.
			function x_function, y_function;
			double tstart, tfinal;
	
	};
	
}

#endif
