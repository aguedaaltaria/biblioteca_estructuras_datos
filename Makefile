CC = gcc
CFLAGS = -Wall -Wextra
SRC = $(wildcard codigo/*.c)
TARGET = programa_main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean valgrind