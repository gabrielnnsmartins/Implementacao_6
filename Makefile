CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = banker
SRC = banker.c

all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)