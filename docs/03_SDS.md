
# Software Design Specification (SDS)

## 1. Architecture Overview

The project is organized as a small reusable library plus three executables:

- **Library**: `twosum` (core algorithms)
- **Executable**: `TwoSumApp` (demo / example usage)
- **Executable**: `TwoSumTest` (unit tests)
- **Executable**: `TwoSumBenchmark` (performance comparison)

This split keeps algorithm code in one place and avoids duplication across test/benchmark/demo.

## 2. Public API

Header: `include/twosum.hpp`

```cpp
std::vector<int> twoSumArray(const std::vector<int>& nums, int target);
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);
```

### Design notes

- **`const std::vector<int>&`**: prevents accidental mutation and reduces copies.
- **Return type `std::vector<int>`**: matches course requirement; `{}` represents “not found”.

## 3. Algorithm Design

### 3.1 `twoSumArray`

Approach:
- Nested loops over all pairs `(i, j)` with `j > i`.
- Return first pair found.

Complexity:
- Time: $O(n^2)$
- Space: $O(1)$ (excluding return value)

### 3.2 `twoSumHashTable`

Approach:
- Keep a map `value -> index` of previously seen values.
- For each `nums[i]`, compute `complement = target - nums[i]`.
- If `complement` exists in the map, return `{index_of_complement, i}`.

Complexity:
- Time: average $O(n)$, worst-case $O(n^2)$ (hash collision scenarios)
- Space: $O(n)$

Implementation choices:
- Reserve hash table capacity (`reserve(nums.size())`) to reduce rehashing.
- Keep the **earliest index** for each value to make duplicate behavior predictable.

## 4. Benchmark Design

Benchmark executable: `src/benchmark.cpp`

Goals:
- Compare brute force vs hash on the *same* generated input.
- Provide a larger “hash-only” case to demonstrate scalability.

Design choices:
- Fixed RNG seed for reproducibility.
- Force a valid pair near the end of the vector.
- Avoid huge `n` for `twoSumArray` because $O(n^2)$ becomes impractical.

## 5. Test Design

Tests are implemented with GoogleTest in `tests/test_twosum.cpp`.

Key strategy:
- A helper validates generic correctness (indices are valid, distinct, and sum to target).
- For canonical small examples, tests also assert the exact expected indices.

## 6. Build & CI Design

- CMake builds targets and uses `FetchContent` for GoogleTest.
- CI runs on GitHub Actions and executes `ctest`.

