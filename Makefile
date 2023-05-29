CC = gcc
CFLAGS = -Wall -Wextra -g

SOURCES = main.c lists.c functions.c tree.c

TARGET = lanParty

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean
