.PHONY: all test-all clean test-lab01 test-lab02 test-lab03 test-lab04

all: test-all

test-all: test-lab01 test-lab02 test-lab03 test-lab04
	@echo "============================================="
	@echo "ALL LABS & EXERCISES PASSED SUCCESSFULLY!"
	@echo "============================================="

test-lab01:
	@echo "--- Testing Lab 01 ---"
	gcc -Wall -Wextra lab01-fundamentals/lab01.c -o lab01-fundamentals/lab01
	./lab01-fundamentals/lab01

test-lab02:
	@echo "--- Testing Lab 02 ---"
	gcc -Wall -Wextra -g lab02-arrays-strings/lab02.c -o lab02-arrays-strings/lab02
	./lab02-arrays-strings/lab02

test-lab03:
	@echo "--- Testing Lab 03 ---"
	gcc -Wall -Wextra -g lab03-pointers-memory/lab03.c -o lab03-pointers-memory/lab03
	./lab03-pointers-memory/lab03

test-lab04:
	@echo "--- Testing Lab 04 ---"
	$(MAKE) -C lab04-structs-modules test

clean:
	rm -f lab01-fundamentals/lab01 lab01-fundamentals/temperature lab01-fundamentals/calculator
	rm -f lab02-arrays-strings/lab02 lab02-arrays-strings/buggy lab02-arrays-strings/letter_frequency
	rm -f lab03-pointers-memory/lab03 lab03-pointers-memory/leaky
	$(MAKE) -C lab04-structs-modules clean
