
# Traceability Matrix

This document traces SRS requirements to code, tests, and acceptance tests.

## Functional Requirements

| Requirement | Description | Implementation | Unit Tests | Acceptance |
|------------|-------------|----------------|-----------|-----------|
| FR-1 | Provide `twoSumArray` | `include/twosum.hpp`, `src/twosum.cpp` | `TwoSumArray.*` | AT-2 |
| FR-2 | Provide `twoSumHashTable` | `include/twosum.hpp`, `src/twosum.cpp` | `TwoSumHashTable.*` | AT-2 |
| FR-3 | Correctness constraints | `src/twosum.cpp` | helper checks in `tests/test_twosum.cpp` | AT-2 |
| FR-4 | Example executable | `src/main.cpp` | (N/A) | AT-3 |
| FR-5 | Unit tests exist | `tests/test_twosum.cpp` | All tests | AT-2 |
| FR-6 | Benchmark executable | `src/benchmark.cpp` | (N/A) | AT-4 |
| FR-7 | CI build+test on push/PR | `.github/workflows/build-and-test.yml` | CI runs `ctest` | AT-5 |

## Non-Functional Requirements

| Requirement | Description | Evidence |
|------------|-------------|----------|
| NFR-1 | Maintainable style | Small library API + separate targets; simple code structure |
| NFR-2 | Build portability | CMake-based; CI on Ubuntu |
| NFR-3 | Deterministic unit tests | Tests are fixed vectors; no randomness |
| NFR-4 | Reproducible benchmark | Fixed RNG seed in benchmark |

