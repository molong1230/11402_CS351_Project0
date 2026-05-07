
# Software Requirements Specification (SRS)

## 1. Overview

This project provides two implementations of the Two Sum problem in C++20 with a clean CMake build, unit tests, CI automation, and a simple benchmark.

## 2. Definitions

- **Two Sum**: Find indices `i != j` such that `nums[i] + nums[j] == target`.
- **Solution**: A returned vector `{i, j}` where indices are valid and distinct.

## 3. Functional Requirements

### FR-1 — Array solution
The system shall provide a brute-force function:

`std::vector<int> twoSumArray(const std::vector<int>& nums, int target);`

- Returns `{i, j}` when a valid pair exists.
- Returns `{}` when no valid pair exists.

### FR-2 — Hash-table solution
The system shall provide an optimized function:

`std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);`

- Returns `{i, j}` when a valid pair exists.
- Returns `{}` when no valid pair exists.

### FR-3 — Correctness constraints
- The returned indices shall be within `[0, nums.size())`.
- The two indices shall be different.
- The values at those indices shall sum to `target`.

### FR-4 — Example executable
The system shall provide a small CLI example program that demonstrates calling one of the implementations and printing the result.

### FR-5 — Unit tests
The system shall provide unit tests covering at least:
- a basic valid example
- negative numbers
- duplicate values
- zero as part of the solution
- small input size and no-solution behavior

### FR-6 — Performance benchmark
The system shall provide a benchmark executable that measures the runtime of both approaches on the same generated inputs and prints the results.

### FR-7 — CI automation
The system shall provide a GitHub Actions workflow that automatically builds the project and runs all unit tests on `push` and `pull_request`.

## 4. Non-Functional Requirements

### NFR-1 — Maintainable style
- Code shall use standard C++ practices and clear naming.
- Avoid unnecessary abstractions.

### NFR-2 — Build portability
- Project shall build with CMake on common platforms.

### NFR-3 — Determinism (tests)
- Unit tests shall be deterministic.

### NFR-4 — Benchmark reproducibility
- Benchmark input generation shall use a fixed random seed.

## 5. Constraints

- Language: C++20
- Build system: CMake (minimum 3.20)
- Testing: GoogleTest (via CMake FetchContent)

## 6. Out of Scope

- Complex CLI argument parsing.
- Multiple output formats.
- Advanced benchmarking methodology.

