
# Test Plan

## 1. Scope

This test plan covers:
- Correctness of `twoSumArray` and `twoSumHashTable`
- Basic regression coverage via unit tests
- CI validation on GitHub Actions
- Informational performance benchmarking

Out of scope:
- Fuzz testing
- Sanitizers/UB checks
- Formal performance statistics

## 2. Test Levels

### 2.1 Unit Tests (GoogleTest)

Location: `tests/test_twosum.cpp`

Required scenarios:
- Basic valid example
- Negative numbers
- Duplicate values
- Zero in solution
- Small input / no solution

Pass criteria:
- All tests pass (`ctest` exit code 0)

### 2.2 CI Tests (GitHub Actions)

Workflow: `.github/workflows/build-and-test.yml`

CI performs:
- Configure: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DTWOSUM_BUILD_TESTS=ON`
- Build: `cmake --build build --config Release`
- Test: `ctest --test-dir build --output-on-failure --build-config Release`

Pass criteria:
- Workflow status is green on `push` and `pull_request`.

## 3. Benchmark Plan

Executable: `TwoSumBenchmark`

Purpose:
- Compare relative runtime of array vs hash.
- Demonstrate that hash-based solution scales to larger inputs.

Inputs:
- Small/medium sizes: run both implementations.
- Large size: run hash-only (avoid excessive runtime).

Reporting:
- Print total runtime in milliseconds for each case and a checksum to prevent dead-code elimination.

## 4. Test Data

Unit tests use small deterministic vectors.
Benchmark uses deterministic pseudo-random data (fixed seed) with a forced valid solution.

## 5. Exit Criteria

- FR-5, FR-7 satisfied (tests exist + CI passes).
- No failing unit tests.

