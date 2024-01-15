# Makefile for compiling and running test.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -fPIC $(shell pkg-config --cflags Qt5Widgets)

# Linker flags
LDFLAGS = $(shell pkg-config --libs Qt5Widgets)

# Output executable
OUTPUT = test

# Source files
SRCS = test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(OUTPUT)

# Rule to compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files to executable
$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT) $(LDFLAGS)

# Rule to run the executable
run: $(OUTPUT)
	./$(OUTPUT)

# Clean up
clean:
	rm -f $(OBJS) $(OUTPUT)
