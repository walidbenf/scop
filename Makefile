CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lGL -lGLU -lglfw

SRC = main.c obj_parser.c renderer.c shader.c
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