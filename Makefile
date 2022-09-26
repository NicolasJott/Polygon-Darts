Project1: point.o fraction.o Project1.o
			g++ -o Project1 point.o fraction.o Project1.o
point.o: point.cpp point.h
			g++ -c point.cpp

fraction.o: fraction.cpp fraction.h
			g++ -c fraction.cpp

Project1.o: Project1.cpp point.h
			g++ -c Project1.cpp


