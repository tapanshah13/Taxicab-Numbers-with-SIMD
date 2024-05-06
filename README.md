# Taxicab Numbers Calculator

This repository contains the C++ implementation for calculating Taxicab numbers using two distinct methods: a traditional algorithm and a SIMD-accelerated approach. Taxicab numbers, also known as Hardy-Ramanujan numbers, are integers that can be expressed as the sum of the cubes of two pairs of positive integers in two different ways. A famous example is the number 1729.

## Description

The `taxicab_problem.cpp` file includes implementations of two main functions designed to calculate the first N Taxicab numbers:

### Functions and Implementation Details

- **`printTaxicab(int N)`**:
  - This function calculates the first N Taxicab numbers using a straightforward iterative approach. It iteratively checks each integer to see if it can be expressed as the sum of cubes of two pairs of integers. If an integer qualifies as a Taxicab number, it is printed along with its sequence number.

- **`printTaxicabSimd(int N)`**:
  - This function utilizes SIMD (Single Instruction, Multiple Data) operations to accelerate the computation of Taxicab numbers. It processes multiple numbers simultaneously using AVX2 instructions, which can significantly speed up the calculation on compatible hardware. The function checks eight numbers at a time for potential Taxicab properties.

### Main Execution Flow

- The program begins by capturing the start time, then calls `printTaxicab(N)` to compute and print the first N Taxicab numbers using the standard method.
- It records the end time, calculates the duration, and prints the time taken.
- The same process is repeated using `printTaxicabSimd(N)` to demonstrate the potential speed improvement with SIMD.
- Finally, it displays a comparison table of execution times for both methods, highlighting the performance benefits of using SIMD.

### Performance Measurement

- The execution times for both the standard and SIMD-accelerated methods are measured and compared to demonstrate the efficiency gains possible with SIMD optimizations.

## Prerequisites

- A modern C++ compiler that supports C++11 standards and above.
- AVX2 support in the CPU and compiler for the SIMD-accelerated function.

## Compilation

To compile the `taxicab_problem.cpp` file with SIMD optimizations, use the following command. Ensure your compiler supports the AVX2 instruction set:

```bash
g++ -O3 -mavx2 -o taxicab_numbers taxicab_problem.cpp
