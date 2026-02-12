# Makefile para compilar Torres de Hanoi (Arquitectura OOP con SOLID)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = hanoi
TEST_TARGET = test_hanoi
SOURCES = main.cpp RecursiveSolver.cpp IterativeSolver.cpp
TEST_SOURCES = test_hanoi.cpp RecursiveSolver.cpp IterativeSolver.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
HEADERS = HanoiSolver.h RecursiveSolver.h IterativeSolver.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJECTS) $(TEST_OBJECTS)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean run test
