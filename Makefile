# Makefile para compilar Torres de Hanoi (Arquitectura OOP con SOLID)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = hanoi
SOURCES = main.cpp RecursiveSolver.cpp IterativeSolver.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = HanoiSolver.h RecursiveSolver.h IterativeSolver.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
