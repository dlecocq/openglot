int mod(int x, int y) {
	return x - int(float(x) / float(y)) * y;
}

float log2(float x) {
	return log(x) / log(2.0);
}

void main () {

	int iteration = 0;
	
	vec4 col = vec4(1, 0, 0, 1);
	
	float temp;
	temp = 0.0;
	float real = float(0);
	float img = float(0);
	
	int it_max = 60;
	
	float max_val = 100.0;
	
	float v;

	for (iteration = 0; iteration < it_max; ++iteration) {
		temp = real;
		real = real * real - img * img + gl_TexCoord[0].x;
		img = 2.0 * temp * img + gl_TexCoord[0].y;
		if ((v = sqrt(real * real + img * img)) > max_val) {
			break;
		}
	}

	if (iteration == it_max) {
		v = sqrt(real * real + img * img);
	}
	
	if (v < 4.0) {
		col = vec4(0, 0, 0, 1);
	} else {
		v /= max_val;
		v = sqrt(v);
		//v = sqrt(sqrt(sqrt(sqrt(sqrt(v)))));
		//v = log(v);
		float red;
		float green;
		float blue;
		
		red = 0.0;
		green = 0.0;
		blue = 0.0;
		
		//blue
		if (v > 0.75) {
			red = 0.0;
			green = (1.0 - v) * 4.0;
			blue = 1.0;
		} else if (v > 0.5) {
			red = (0.75 - v) * 4.0;
			green = 1.0;
			blue = (v - 0.5) * 4.0;
		} else if (v > 0.25) {
			red = 1.0;
			green = 0.25 + v * 2.0;
		} else {
			red = 1.0;
			green = 3.0 * v;
		}
		//red

		col = vec4(red, green, blue, 1.0);
	}
	
	gl_FragColor = col;
}