#ifndef FLOW_H
#define FLOW_H

#include <GL/glew.h>

#include <string>

#include "shader_primitive.h"
#include "color.h"

using namespace std;

namespace glot {

	/** \brief curve: a contour to plot
	  *
		* This class takes a function that accepts two doubles,
		* interprets it as a scalar field, and then plots it
		*
		* \sa grapher
		* \sa vector_field
	  */
	class flow : public shader_primitive {
	
		public:
			
			/** Color variable
			  *
			  * This is the color the contour is supposed to
			  * take on.
			  */
			color c;
		
			/** Constructor
			  *	\param func - the function to render
			  *	\param col - the color of the curve
			  */
			flow(const string& f, const color& col) : shader_primitive(col), func(f) {
				gen_shader();
			};
			
			void dl_gen(const screen& scr);
		
		private:
			
			void gen_shader();
			
			//string get_frag_shader();
			string get_vert_shader();
			string get_geom_shader();
			
			//GLhandleARB f;
			GLhandleARB g;
			GLhandleARB v;
		
			// This is the function it's meant to plot.
			string func;
	
	};
	
}

#endif
