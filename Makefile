

CXX = g++
CXXFLAGS = -Wall

all: build

MathLib.o: MathLib.h


clean:
	-rm MathLib.o
	-rm MathLib


build: demo.cpp MathLib.o
	$(CXX) $(CXXFLAGS) -o MathLib demo.cpp MathLib.o
