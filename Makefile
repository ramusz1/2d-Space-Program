SRC_DIR := src
OBJ_DIR := obj
# SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -lGL -lGLEW -lglfw
#CPPFLAGS := ...
CXXFLAGS := --std=c++17
CXX := g++
PROGRAM := main.out

all: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	find $(OBJ_DIR) -name "*.o" -type f -delete
	rm -f $(PROGRAM)
