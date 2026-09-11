CXX := g++
CXXFLAGS := -O3 -std=c++11 -Wall -Wextra
LDFLAGS := -pthread
TARGETS := vector matrix

.PHONY: all clean

all: $(TARGETS)

vector: vector.cpp simple-multithreader.h
	$(CXX) $(CXXFLAGS) -o $@ vector.cpp $(LDFLAGS)

matrix: matrix.cpp simple-multithreader.h
	$(CXX) $(CXXFLAGS) -o $@ matrix.cpp $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o
