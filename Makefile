
# Compiler to use
CXX = g++

# Compiler options: use C++17 and show common warnings
CXXFLAGS = -std=c++17 -Wall -Wextra

# Name of the executable to build
TARGET = slm

# Object files needed to build the executable
OBJECTS = src/main.o src/trainmodel.o src/generatemodel.o


# Default target: running "make" builds the program
all: $(TARGET)


# Link the object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^


# Compile main.cpp; rebuild if either header it uses changes
src/main.o: src/main.cpp src/trainmodel.h src/generatemodel.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o


# Compile trainmodel.cpp; rebuild if its header changes
src/trainmodel.o: src/trainmodel.cpp src/trainmodel.h
	$(CXX) $(CXXFLAGS) -c src/trainmodel.cpp -o src/trainmodel.o


# Compile generatemodel.cpp; rebuild if its header changes
src/generatemodel.o: src/generatemodel.cpp src/generatemodel.h
	$(CXX) $(CXXFLAGS) -c src/generatemodel.cpp -o src/generatemodel.o


# Remove generated object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)


# These targets are commands, not files
.PHONY: all clean


