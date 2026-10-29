# VGU Programming 1 - Exercises & Complete Solutions
**Vietnamese-German University (VGU) - Computer Science Engineering (CSE)**

Kho lưu trữ mã nguồn giải chi tiết toàn bộ bài tập thực hành môn **Lập Trình 1 (CSE Programming 1)**.
Tất cả các bài tập đều được viết bằng C chuẩn C99/C11, chú thích cặn kẽ, vượt qua 100% các bài test và không rò rỉ bộ nhớ (0 errors, no leaks trong Valgrind).

## Cấu trúc Repository

```
├── README.md
├── Makefile
├── .gitignore
├── lab01-fundamentals/
│   └── lab01.c                 # 1.1 → 1.8 (All PASS)
├── lab02-arrays-strings/
│   ├── lab02.c                 # 2.1 → 2.10 (All PASS)
│   └── buggy_fixed.c           # Sửa 4 lỗi GDB
├── lab03-pointers-memory/
│   ├── lab03.c                 # 3.1 → 3.9 (All PASS + Valgrind clean)
│   └── leaky_fixed.c           # Sửa 4 lỗi memory
└── lab04-structs-modules/
    ├── student.h
    ├── student.c
    ├── test_student.c
    └── Makefile
```

## Hướng dẫn chạy

```bash
# Lab 1
cd lab01-fundamentals && gcc -Wall -Wextra lab01.c -o lab01 && ./lab01

# Lab 2
cd lab02-arrays-strings && gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02

# Lab 3
cd lab03-pointers-memory && gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03
valgrind --leak-check=full ./lab03

# Lab 4
cd lab04-structs-modules && make test && make valgrind
```

Hoặc chạy tất cả từ root:
```bash
make test-all
```

## Tác giả
HarryJame3004 (Trần Ngọc Minh Khôi) - VGU CSE
