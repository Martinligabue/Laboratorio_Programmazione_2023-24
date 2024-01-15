# Makefile for compiling and running test.cpp
# g++ $(pkg-config --cflags --libs Qt5Widgets) -fPIC -o test test.cpp
# Compiler

CXX = g++

# Compiler flags
CXXFLAGS = -fPIC $(shell pkg-config --cflags Qt5Widgets)

# Linker flags
LDFLAGS = $(shell pkg-config --libs Qt5Widgets)

# Output executables
OUTPUT_TEST = test
OUTPUT_HELLO = hello

# Source files
SRCS_TEST = test.cpp
SRCS_HELLO = hello.cpp

# Object files
OBJS_TEST = $(SRCS_TEST:.cpp=.o)
OBJS_HELLO = $(SRCS_HELLO:.cpp=.o)

# Default target
all: $(OUTPUT_TEST) $(OUTPUT_HELLO)

# Rule to compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files to executables
$(OUTPUT_TEST): $(OBJS_TEST)
	$(CXX) $(OBJS_TEST) -o $(OUTPUT_TEST) $(LDFLAGS)

$(OUTPUT_HELLO): $(OBJS_HELLO)
	$(CXX) $(OBJS_HELLO) -o $(OUTPUT_HELLO) $(LDFLAGS)

# Rule to run the executables
run: $(OUTPUT_TEST) $(OUTPUT_HELLO)
	./$(OUTPUT_TEST)
	./$(OUTPUT_HELLO)

# Clean up
clean:
	rm -f $(OBJS_TEST) $(OBJS_HELLO) $(OUTPUT_TEST) $(OUTPUT_HELLO)
