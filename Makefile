CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinc
LDFLAGS = -lGL -lGLU -lglfw -lGLEW

SRC = main.c src/obj_parser.c src/renderer.c src/shader.c
OBJ = $(SRC:.c=.o)
EXEC = 3d_viewer

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean