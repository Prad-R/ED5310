BINARY := triangulate.bin

CXX := g++
DEPFLAGS := -MP -MMD
CXXFLAGS := $(DEPFLAGS)

CPPFILES := $(wildcard *.cpp)
HFILES := $(wildcard *.hpp)
OBJECTS := $(patsubst %.cpp, %.o, $(CPPFILES))
DEPFILES := $(patsubst %.cpp, %.d, $(CPPFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo "Linking object files ....."
	$(CXX) -o $@ $^

%.o: %.cpp
	@echo "Compiling source code ....."
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@echo "Removing all object files and dependency files ....."
	rm -rf $(BINARY) $(DEPFILES) $(OBJECTS)

-include $(DEPFILES)

# Test command to see if all the files are included

files:
	@echo "Source files are :" $(HFILES)
	@echo "Header files are :" $(CPPFILES)
	@echo "Object files are :" $(OBJECTS)
	@echo "Dependency files are :" $(DEPFILES)