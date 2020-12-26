all: libcircle_c.a
	gcc main.c -L. -lcircle_c -lstdc++ -o mixed

libcircle.a: circle.o
	ar -r libcircle.a circle.o
circle.o: circle.cpp circle.h
	g++ -c circle.h circle.cpp

libcircle_c.a: circle.o circle_c.o
	ar -r libcircle_c.a circle_c.o circle.o
circle_c.o: circle.cpp circle.h
	g++ -c circle_c.h circle_c.cpp

.PHONY: clean

clean:
	rm -rf *.o *.a *.gch
