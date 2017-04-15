#ifndef SCALAR_FIELD_H
#define SCALAR_FIELD_H

#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <string>
#include <cmath>

#include "shader_primitive.h"
#include "function.h"
#include "color.h"

namespace glot {

	/** \brief curve: a curve to plot
	  *
		* This class takes a function that accepts a double
		* and returns a double and does its best to plot it
		* in the grapher.
		*
		* \sa grapher
		* \sa p_curve
	  */
	class scalar_field : public shader_primitive {
	
		public:
			
			/** Color variable
			  *
			  * This is the color the curve is supposed to
			  * take on.
			  */
			color c;
		
			/** Constructor
			  *	\param func - the function to render
			  *	\param col - the color of the curve
			  */
			scalar_field(string func, const color& col) : shader_primitive(col), f(func), t(0) {
				gen_shader();
			};
			
			void dl_gen(const screen& s);
		
		private:
		
			void gen_shader();
			
			//GLenum p;
		
			// This is the function it's meant to plot.
			string f;
			double t;
	
	};
	
}

#endif
