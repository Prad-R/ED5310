BINARY := incremental.bin

CXX := g++
DEPFLAGS := -MP -MMD
CXXFLAGS := -std=c++17  $(DEPFLAGS)

DEP_DIR := Dep_Files
OBJ_DIR := Object_Files

CPPFILES := $(wildcard *.cpp)
HFILES := $(wildcard *.hpp)
OBJECTS := $(patsubst %.cpp, %.o, $(CPPFILES))
DEPFILES := $(patsubst %.cpp, %.d, $(CPPFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo "Linking object files ....."
	$(CXX) -o $@ $^
	make move

%.o: %.cpp
	@echo "Compiling source code ....."
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@echo "Removing all object files and dependency files ....."
	rm -rf $(BINARY) $(DEP_DIR)/*.d $(OBJ_DIR)/*.o *.d *.o

-include $(DEPFILES)

# Test command to see if all the files are included

files:
	@echo "Source files are :" $(HFILES)
	@echo "Header files are :" $(CPPFILES)
	@echo "Object files are :" $(OBJECTS)
	@echo "Dependency files are :" $(DEPFILES)

# Command to move all the object and dependency files to different folders

move:
	mv *.d $(DEP_DIR)/
	mv *.o $(OBJ_DIR)/