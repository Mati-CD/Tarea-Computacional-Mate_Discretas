NAME = path

SOURCES := $(wildcard *.c)

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "Compilando $(NAME)..."
	$(CC) $(SOURCES) -o $(NAME)

clean:
	@echo "Limpiando ejecutable ..."
	rm -f $(NAME)

.PHONY: all clean