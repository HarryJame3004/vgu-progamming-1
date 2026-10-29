CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUG_FLAGS = -g -DDEBUG

.PHONY: all test debug valgrind app clean

all: test

test: test_student
	./test_student

test_student: test_student.o student.o
	$(CC) $(CFLAGS) $^ -o $@

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean test_student
	./test_student

valgrind: test_student
	valgrind --leak-check=full --track-origins=yes ./test_student

app: app.o student.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o test_student app
