#ifndef SHADER_PRIMITIVE_H
#define SHADER_PRIMITIVE_H

#include <fstream>
#include <string>

#include <GL/glew.h>

#include "primitive.h"
#include "screen.h"
#include "color.h"

using namespace std;

namespace glot {
	
	class shader_primitive {
	
		public:
		
			/** The color of the the point */
			color c;
					
			shader_primitive(const color& col) : c(col), p(0) {};
			
			virtual ~shader_primitive() {};
			
			virtual void dl_gen(const screen& s) = 0;
			
			void printProgramInfoLog(GLuint obj);
			void printShaderInfoLog(GLuint obj);
			
			string read_file(const char * filename);
			
			GLenum p;
		
		protected:
		
		private:
	
	};

}

#endif
