CC = gcc
CFLAGS = -Wall

TARGET = fork_exec

all: $(TARGET)

$(TARGET): fork_exec.c
	$(CC) $(CFLAGS) fork_exec.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
