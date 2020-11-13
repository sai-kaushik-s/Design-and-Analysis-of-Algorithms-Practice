all: sorting2

sorting2: main.o divide.o conquer.o
	g++ main.o divide.o conquer.o -o sorting2
	
main.o: main.cpp
	g++ -c main.cpp
	
divide.o: divide.cpp
	g++ -c divide.cpp
	
conquer.o: conquer.cpp
	g++ -c conquer.cpp
	
clean:
	rm -rf *o sorting2
