# Makefile for decifrar_relatorio project
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# List of source files
SRCS = src/decifrar_relatorio.c src/leitura.c src/erros.c src/saida.c src/main.c

# List of object files
OBJS = $(SRCS:.c=.o)

# Binary executable
TARGET = decifrar_relatorio

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
