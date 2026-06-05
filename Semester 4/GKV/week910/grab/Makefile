CXX = clang++
CXXFLAGS = -Wall -std=c++17 -I./include
# Using both deprecation silence flags for max compatibility between OS versions
CXXFLAGS += -DGL_SILENCE_DEPRECATION -Wno-deprecated-declarations

# Detect the Operating System
UNAME_S := $(shell uname -s)

# Apply macOS-specific or Linux-specific linking flags
ifeq ($(UNAME_S), Darwin)
    # macOS (Darwin) uses Apple Frameworks
    LDFLAGS = -framework OpenGL -framework GLUT
else
    # Linux uses standard library links
    LDFLAGS = -lglut -lGL -lGLU
endif

SRC = main.cpp
OUT = bin/main

all: build run

build:
	mkdir -p bin
	$(CXX) $(SRC) $(CXXFLAGS) $(LDFLAGS) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -rf bin/main