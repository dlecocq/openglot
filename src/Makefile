CC = g++
CCOPT = -O3 -Wall -g

DEMOS = demos

LIBOPT = -framework GLUT -framework OpenGL -lGLEW

DEPENDENCIES = grapher.o function.o curve.o p_curve.o point.o line.o vector.o vector_field.o contour.o scalar_field.o stopwatch.o shader_primitive.o flow.o

SOURCE = grapher.h grapher.cpp function.h function.cpp curve.h curve.cpp p_curve.h p_curve.cpp point.h point.cpp driver.cpp Makefile

EXECUTABLE = glot

all : $(EXECUTABLE)

$(EXECUTABLE) : driver.o $(DEPENDENCIES)
	$(CC) $(CCOPT) -o $(EXECUTABLE) driver.o $(DEPENDENCIES) $(LIBOPT)
	
driver.o : driver.cpp Makefile
	$(CC) $(CCOPT) -c driver.cpp
	
grapher.o : grapher.h grapher.cpp
	$(CC) $(CCOPT) -c grapher.cpp
	
function.o : function.h function.cpp
	$(CC) $(CCOPT) -c function.cpp

curve.o : curve.h curve.cpp
	$(CC) $(CCOPT) -c curve.cpp
	
p_curve.o : p_curve.h p_curve.cpp
	$(CC) $(CCOPT) -c p_curve.cpp
	
point.o : point.h point.cpp
	$(CC) $(CCOPT) -c point.cpp
	
line.o : line.h line.cpp
	$(CC) $(CCOPT) -c line.cpp
	
vector.o : vector.h vector.cpp
	$(CC) $(CCOPT) -c vector.cpp
	
vector_field.o : vector_field.h vector_field.cpp
	$(CC) $(CCOPT) -c vector_field.cpp

contour.o : contour.h contour.cpp
	$(CC) $(CCOPT) -c contour.cpp

scalar_field.o : scalar_field.h scalar_field.cpp
	$(CC) $(CCOPT) -c scalar_field.cpp
	
stopwatch.o : stopwatch.h stopwatch.cpp
	$(CC) $(CCOPT) -c stopwatch.cpp
	
shader_primitive.o : shader_primitive.h shader_primitive.cpp
	$(CC) $(CCOPT) -c shader_primitive.cpp
	
flow.o : flow.h flow.cpp
	$(CC) $(CCOPT) -c flow.cpp
	
# The demos
newton : newton.o $(DEPENDENCIES)
	$(CC) $(CCOPT) -o newton newton.o $(DEPENDENCIES) $(LIBOPT)

newton.o : newton.cpp
	$(CC) $(CCOPT) -c newton.cpp
	
demos : curve_demo contour_demo scalar_field_demo flow_demo

curve_demo : $(DEMOS)/curve_demo.o $(DEPENDENCIES)
	$(CC) $(CCOPT) -o $(DEMOS)/curve_demo $(DEMOS)/curve_demo.o $(DEPENDENCIES) $(LIBOPT)

curve_demo.o : $(DEMOS)/curve_demo.cpp
	$(CC) $(CCOPT) -c $(DEMOS)/curve_demo.cpp
	mv curve_demo.o $(DEMOS)
	
contour_demo : $(DEMOS)/contour_demo.o $(DEPENCENCIES)
	$(CC) $(CCOPT) -o $(DEMOS)/contour_demo $(DEMOS)/contour_demo.o $(DEPENDENCIES) $(LIBOPT)

contour_demo.o : $(DEMOS)/contour_demo.cpp
	$(CC) $(CCOPT) -c $(DEMOS)/contour_demo.cpp
	mv contour_demo.o $(DEMOS)
	
scalar_field_demo : $(DEMOS)/scalar_field_demo.o $(DEPENDENCIES)
	$(CC) $(CCOPT) -o $(DEMOS)/scalar_field_demo $(DEMOS)/scalar_field_demo.o $(DEPENDENCIES) $(LIBOPT)

scalar_field_demo.o : $(DEMOS)/scalar_field_demo.cpp
	$(CC) $(CCOPT) -c $(DEMOS)/scalar_field_demo.cpp
	mv scalar_field_demo.o $(DEMOS)

flow_demo : $(DEMOS)/flow_demo.o $(DEPENDENCIES)
	$(CC) $(CCOPT) -o $(DEMOS)/flow_demo $(DEMOS)/flow_demo.o $(DEPENDENCIES) $(LIBOPT)
	
flow_demo.o : $(DEMOS)/flow_demo.cpp
	$(CC) $(CCOPT) -c $(DEMOS)/flow_demo.cpp
	mv flow_demo.o $(DEMOS)

clean :
	find . -type f -name '*.o' -o -name '*.dSYM' -o -name '*.dylib' | xargs rm -rf
	
tarball : $(SOURCE)
	cd ..
	mv src openglot
	tar -cvzf openglot.tar.gz openglot
	mv openglot src
	cd src
	