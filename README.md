# Simple Multithreader

A lightweight C++ parallel-for library built with POSIX threads (`pthread`) that supports both 1D and 2D iteration spaces.

## Features

- 1D `parallel_for` for vector-style workloads
- 2D `parallel_for` for matrix-style workloads
- POSIX thread creation and joining
- Balanced chunk distribution with remainder handling
- Lambda-based task execution
- Execution-time measurement
- Included vector-addition and matrix-multiplication tests

## Build

```bash
make
```

## Run

```bash
./vector 4 1000000
./matrix 4 512
```

The first argument selects the number of worker threads; the second controls problem size.

## Architecture

```text
parallel_for()
      |
      +---- divide iteration space
      |
      +---- create pthread workers
      |       |       |       |
      |      T1      T2      T3 ...
      |       |       |       |
      +---- join all workers
      |
      +---- report execution time
```

The iteration range is divided into contiguous chunks. Any remainder is distributed across the first workers so all iterations are covered without overlap.

## OS / systems concepts

- Multithreading with POSIX `pthread`
- Work partitioning
- Thread lifecycle management
- Synchronization through `pthread_join`
- Parallel execution and performance measurement

## Portfolio value

This project demonstrates practical understanding of thread creation, workload partitioning, parallel computation, and low-level concurrency APIs.

## Author

Dhruv Dagar
