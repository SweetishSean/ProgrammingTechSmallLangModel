
# Compiler to use
CXX = g++

# Compiler options: use C++17 and show common warnings
CXXFLAGS = -std=c++17 -Wall -Wextra

# Name of the executable to build
TARGET = slm

# Object files needed to build the executable
OBJECTS = main.o trainmodel.o generatemodel.o


# Default target: running "make" builds the program
all: $(TARGET)


# Link the object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^


# Compile main.cpp; rebuild if either header it uses changes
main.o: main.cpp trainmodel.h generatemodel.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


# Compile c1.cpp; rebuild if its header changes
c1.o: trainmodel.cpp trainmodel.h
	$(CXX) $(CXXFLAGS) -c trainmodel.cpp -o trainmodel.o


# Compile c2.cpp; rebuild if its header changes
c2.o: generatemodel.cpp generatemodel.h
	$(CXX) $(CXXFLAGS) -c generatemodel.cpp -o generatemodel.o


# Remove generated object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)


# These targets are commands, not files
.PHONY: all clean


