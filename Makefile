.PHONY: all test-all clean test-lab01 test-lab02 test-lab03 test-lab04 homework

all: test-all

test-all: test-lab01 test-lab02 test-lab03 test-lab04
	@echo ""
	@echo "============================================="
	@echo "  ALL LABS PASSED SUCCESSFULLY!"
	@echo "============================================="

test-lab01:
	@echo "--- Lab 01 ---"
	gcc -Wall -Wextra lab01-fundamentals/lab01.c -o lab01-fundamentals/lab01
	./lab01-fundamentals/lab01

test-lab02:
	@echo "--- Lab 02 ---"
	gcc -Wall -Wextra -g lab02-arrays-strings/lab02.c -o lab02-arrays-strings/lab02
	./lab02-arrays-strings/lab02

test-lab03:
	@echo "--- Lab 03 ---"
	gcc -Wall -Wextra -g lab03-pointers-memory/lab03.c -o lab03-pointers-memory/lab03
	./lab03-pointers-memory/lab03

test-lab04:
	@echo "--- Lab 04 ---"
	$(MAKE) -C lab04-structs-modules test

homework:
	@echo "--- Building homework ---"
	gcc -Wall -Wextra lab01-fundamentals/temperature.c -o lab01-fundamentals/temperature -lm
	gcc -Wall -Wextra lab01-fundamentals/calculator.c -o lab01-fundamentals/calculator -lm
	gcc -Wall -Wextra lab02-arrays-strings/my_atoi.c -o lab02-arrays-strings/my_atoi
	gcc -Wall -Wextra lab02-arrays-strings/letter_frequency.c -o lab02-arrays-strings/letter_frequency
	$(MAKE) -C lab04-structs-modules app
	@echo "Homework binaries ready."

clean:
	rm -f lab01-fundamentals/lab01 lab01-fundamentals/temperature lab01-fundamentals/calculator
	rm -f lab02-arrays-strings/lab02 lab02-arrays-strings/buggy lab02-arrays-strings/my_atoi lab02-arrays-strings/letter_frequency
	rm -f lab03-pointers-memory/lab03 lab03-pointers-memory/leaky
	$(MAKE) -C lab04-structs-modules clean
