#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "screen.h"
#include "color.h"

namespace glot {
	
	class primitive {
	
		public:
		
			/** The color of the the point */
			color c;
					
			primitive(const color& col) : c(col), p(0) {};
			
			virtual ~primitive() {};
			
			virtual void dl_gen(const screen& s) = 0;
			
			/*
			y_coord_transform();
			x_coord_transform();
			*/
			
			GLenum p;
		
		protected:
		
		private:
	
	};

}

#endif
