# CPP_EX2_25

This project implements a `SquareMat` class to represent square matrices of real numbers. It includes a variety of overloaded operators and robust error handling.

## Features
-  Matrix addition, subtraction: `+`, `-`
-  Unary minus: `-mat`
-  Scalar multiplication and division: `*`, `/`
-  Matrix multiplication: `mat1 * mat2`
-  Element-wise multiplication: `mat1 % mat2`
-  Modulo operation with scalar: `mat % int`
-  Matrix power: `mat ^ n`
-  Transpose: `~mat`
-  Determinant: `!mat`
-  Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
-  Indexing: `mat[i][j]`
-  Pre/post increment and decrement: `++mat`, `mat++`, `--mat`, `mat--`
-  Compound assignment: `+=`, `-=`, `*=`, `/=`, `%=`
-  Exception handling for invalid operations

## File Structure
- `SquareMat.hpp` – Class definition
- `SquareMat.cpp` – Class implementation
- `main.cpp` – Demonstrates usage of all features
- `test_SquareMat.cpp` – Unit tests using [doctest](https://github.com/doctest/doctest)
- `Makefile` – Contains the following commands:
  - `make Main` – Compile and run the main demo
  - `make test` – Run all unit tests
  - `make valgrind` – Check memory safety using Valgrind
  - `make clean` – Remove generated files

## Compilation & Usage
```
make Main      # Run demo program
make test      # Run unit tests
make valgrind  # Run memory check
make clean     # Cleanup
```

## Notes
- All matrix inputs are validated for correctness (e.g., square shape, non-empty), and exceptions are thrown for invalid usage.
- The code is cleanly organized into headers and source files, with modular structure and meaningful comments.
- Each operator and function is thoroughly tested using `doctest`, with edge cases and exception handling.
- Memory usage is verified using `valgrind` to ensure no memory leaks.

---
Good luck reviewing!
