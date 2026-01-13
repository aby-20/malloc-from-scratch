# Simple Memory Allocator in C

## Overview
Educational implementation of malloc/free to understand heap memory management.

## Features
- Heap allocation using sbrk
- Block metadata and free list
- Block reuse (first-fit)

## Non-goals
- Thread safety
- Production performance
- Replacement for libc malloc

## Memory Layout
[ block header ][ user memory ]

## Limitations
- No coalescing
- No thread safety
