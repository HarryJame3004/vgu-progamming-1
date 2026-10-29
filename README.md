# VGU Programming 1 — Complete Solutions

**Vietnamese-German University (VGU)** · Computer Science Engineering (CSE)

> Full solutions for **CSE Programming 1** labs.  
> Written in standard C99/C11 · heavily commented · 100% test pass · Valgrind clean (0 leaks).

---

## Repository Structure

```
vgu-progamming-1/
├── README.md
├── Makefile                          # make test-all
├── .gitignore
│
├── lab01-fundamentals/
│   ├── lab01.c                       # Exercises 1.1 – 1.8
│   ├── temperature.c                 # Homework 1.9  (F → C table)
│   └── calculator.c                  # Homework 1.10 (menu calculator)
│
├── lab02-arrays-strings/
│   ├── lab02.c                       # Exercises 2.1 – 2.10
│   ├── buggy_fixed.c                 # 4 bugs fixed + notes
│   ├── my_atoi.c                     # Homework 2.11
│   └── letter_frequency.c            # Homework 2.12
│
├── lab03-pointers-memory/
│   ├── lab03.c                       # Exercises 3.1 – 3.9  (Valgrind clean)
│   └── leaky_fixed.c                 # 4 memory bugs fixed
│
└── lab04-structs-modules/
    ├── student.h                     # Struct, linked list, function pointers
    ├── student.c                     # Implementation
    ├── test_student.c                # Automated tests
    ├── app.c                         # Homework 4.5 – interactive CLI
    └── Makefile                      # make test / debug / valgrind / app
```

---

## Quick Start

```bash
# Clone
git clone https://github.com/HarryJame3004/vgu-progamming-1.git
cd vgu-progamming-1

# Run everything
make test-all
```

### Individual labs

| Lab | Command |
|-----|---------|
| **Lab 1** | `cd lab01-fundamentals && gcc -Wall -Wextra lab01.c -o lab01 && ./lab01` |
| **Lab 2** | `cd lab02-arrays-strings && gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02` |
| **Lab 3** | `cd lab03-pointers-memory && gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03` |
| **Lab 4** | `cd lab04-structs-modules && make test` |

### Homework examples

```bash
# Temperature table
echo "0 300 20" | ./lab01-fundamentals/temperature

# Calculator
./lab01-fundamentals/calculator

# Letter frequency
echo "Hello World" | ./lab02-arrays-strings/letter_frequency

# Student manager CLI
cd lab04-structs-modules && make app && ./app
```

### Valgrind (Lab 3 & 4)

```bash
valgrind --leak-check=full --track-origins=yes ./lab03-pointers-memory/lab03
cd lab04-structs-modules && make valgrind
```

---

## Lab Overview

### Lab 01 — C Fundamentals
- `add`, `sum_digits`, `factorial`, Fibonacci (recursive + iterative)
- `is_prime`, `gcd` (Euclid), leap year, `days_in_month` (switch)

### Lab 02 — Arrays & Strings
- `array_max`, `array_mean`, `reverse_array`, `count_value`
- 2-D max along axis, matrix multiplication
- `my_strlen`, `to_upper`, `is_palindrome`, `count_words`
- Debugging exercise with 4 fixed bugs

### Lab 03 — Pointers & Dynamic Memory
- `swap`, `min_max`, pointer-only sum, `copy_array`, `filter_even`
- `my_strdup`, dynamic array `push_back` (doubling capacity)
- 2-D matrix allocate / free, `allocate_int` (double pointer)
- All Valgrind clean

### Lab 04 — Structs, Linked List & Modules
- `Student` + singly linked list (`push_front/back`, `find`, `remove`, `free`)
- Function pointers: `qsort` comparators, `count_if`, `is_excellent`
- Multi-file project with proper Makefile
- Interactive CLI application (`app.c`)

---

## Requirements

- `gcc` or `clang` (C99+)
- `make`
- `valgrind` (recommended for Lab 3 & 4)
- `gdb` (optional, for debugging exercises)

---

## Author

**Trần Ngọc Minh Khôi** · VGU CSE  
Repo: [HarryJame3004/vgu-progamming-1](https://github.com/HarryJame3004/vgu-progamming-1)
