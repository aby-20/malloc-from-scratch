# malloc-from-scratch
A Simple Project
# Simple Memory Allocator in C

## Overview
This project is an educational implementation of a simple memory allocator
(`malloc` / `free`) written in C.

The goal is to understand how heap memory management works at a low level:
how memory is requested from the OS, how allocations are tracked, and how
freed memory is reused.

This is **not** a replacement for the system allocator and is not intended
for production use.

---

## What This Project Implements
- Heap growth using `sbrk`
- Block metadata stored alongside user memory
- Singly linked free list
- Reuse of freed blocks (first-fit strategy)
- Basic safety checks for `free(NULL)`

---

## What This Project Does NOT Aim To Do
- Thread safety
- High-performance optimizations
- Full POSIX `malloc` behavior
- Replace glibc / musl allocators

The focus is correctness and understanding, not performance.

---

## Memory Layout
Each allocation is laid out in memory as:

