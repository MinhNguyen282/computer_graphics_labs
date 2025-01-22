# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -g -I.

# Linker flags
LDFLAGS := -lglut -lGLU -lGL

# Target executable name
TARGET := draw_object

# Source files
SRCS := main.cpp Objects/LineDDA.cpp

# Object files (replace .cpp with .o)
OBJS := $(SRCS:.cpp=.o)

# Dependency files
DEPS := $(OBJS:.o=.d)

# Default rule
.PHONY: all
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Include dependency files
-include $(DEPS)

# Compilation rule with automatic dependency generation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Additional rule for source files in subdirectories
Objects/%.o: Objects/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Clean up generated files
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)