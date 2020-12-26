all: libcircle_c.a
	g++ main.cpp -L. -lcircle_c -std=c++11  -o mixed


libcircle_c.a: circle_c.o
	ar -r libcircle_c.a circle_c.o
circle_c.o: circle_c.h circle_c.c
	gcc -c circle_c.h circle_c.c

.PHONY: clean
clean:
	rm -rf *.o *.a *.gch
