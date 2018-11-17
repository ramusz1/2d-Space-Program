SRC_DIR := src
OBJ_DIR := obj
# SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -lGL -lGLEW -lglfw
INCLUDE_PATHS := -Isrc/
CPPFLAGS := $(INCLUDE_PATHS)
CXXFLAGS := --std=c++17
CXX := g++
PROGRAM := main.out

TMP_FILE := /tmp/2d-kerbals-make-temp-file

all: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	find $(OBJ_DIR) -name "*.o" -type f -delete
	rm -f $(PROGRAM)

recreate_obj_structure:
	rm -rdf $(OBJ_DIR)
	mkdir $(OBJ_DIR)
	cd $(SRC_DIR) && find . -type d > $(TMP_FILE)
	cd $(OBJ_DIR) && xargs mkdir -p < $(TMP_FILE)
	rm $(TMP_FILE)
