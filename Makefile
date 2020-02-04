CXX=g++
CXXFLAGS=-Wall

all: build

Mathlib.o: Mathlib.h

clean:
	-rm Mathlib.o
	-rm Mathlib

build: demo.cpp Mathlib.o
	$(CXX) $(CXXFLAGS) -o Mathlib demo.cpp Mathlib.o
