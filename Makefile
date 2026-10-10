CC = gcc
CFLAGS = -Wall -Wextra -std=c17

TARGET = schondows

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)