CC = g++
CFLAGS = -Wall -Wextra -O2 -Iinc
LDFLAGS = -lGL -lGLU -lglfw -lGLEW

SRC = main.cpp src/obj_parser.cpp src/renderer.cpp src/shader.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = 3d_viewer

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean