COMP = g++
STANDARD = c++14
INCLUDE = src/
LIBS = -lGL -lGLEW -lglfw


all: compile run

run:
	./a.out

compile:
	$(COMP) -I=$(INCLUDE) src/main.cpp src/Window.cpp src/UniverseView.cpp src/UniverseModel.cpp src/shaders/ShaderCompiler.cpp src/models/Drawable.cpp src/models/Triangle.cpp $(LIBS) --std=$(STANDARD)
