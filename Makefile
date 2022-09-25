Project1: point.o fraction.o project1.o
			g++ -o point.o fraction.o project1.o

point.o: point.cpp point.h
			g++ -c point.cpp

fraction.o: fraction.cpp fraction.h
			g++ -c fraction.cpp

project1.o: Project1.cpp
			g++ -c project1.cpp

clean:
	rm *.o Project1