Project1: point.o fraction.o test.o
			g++ -o point.cpp fraction.cpp
point.o: point.cpp point.h
			g++ -c point.cpp
fraction.o: fraction.cpp fraction.h
			g++ -c fraction.cpp
test.o: Project1.cpp
			g++ -c test.cpp