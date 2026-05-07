
# Implementation Plan

## Milestones

### M1 — Project scaffolding
- Create CMake project with a reusable library target (`twosum`).
- Create executables:
	- `TwoSumApp` (simple example runner)
	- `TwoSumBenchmark` (performance comparison)
	- `TwoSumTest` (unit tests)

### M2 — Core algorithms
- Implement:
	- `twoSumArray(nums, target)` — brute force $O(n^2)$
	- `twoSumHashTable(nums, target)` — hash map average $O(n)$
- Ensure const-correct signatures.

### M3 — Unit tests
- Add GoogleTest via `FetchContent`.
- Add required test cases:
	- basic valid example
	- negative numbers
	- duplicate values
	- zero in solution
	- small input sizes / no solution

### M4 — CI automation
- Add GitHub Actions workflow to build + run `ctest` on `push` and `pull_request`.

### M5 — Benchmark
- Implement benchmark executable with reproducible random input (fixed seed).
- Compare array vs hash for moderate sizes; include a larger input case for hash-only.

## Work Breakdown

| Task | Output | Done When |
|------|--------|----------|
| CMake setup | `CMakeLists.txt` | `cmake --build build` succeeds |
| Library API | `include/twosum.hpp` | Functions compile and link |
| Algorithms | `src/twosum.cpp` | All unit tests pass |
| Tests | `tests/test_twosum.cpp` | `ctest` passes locally |
| CI | `.github/workflows/build-and-test.yml` | CI green on push |
| Benchmark | `src/benchmark.cpp` | Runs and prints timings |

## Risks
- Benchmark variability: results depend on hardware/load.
- Brute force cost: avoid too-large inputs for `twoSumArray`.

## Definition of Done
- All requirements in SRS are implemented.
- CI is green.
- Documentation updated.

