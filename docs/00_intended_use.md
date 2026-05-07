# Intended Use / Problem Definition

## 1. Problem Statement
- **What problem does this tool solve?** Given an integer array `nums` and an integer `target`, find indices of two *distinct* elements such that their sum equals `target`.
- **Who is the user?** Students and developers who want to compare two standard approaches (brute force vs hash table) and practice a clean C++/CMake/CI workflow.

## 2. Intended Use
This project provides two implementations of the Two Sum problem and a small benchmark program to compare their performance.
It is designed for education, CI-based verification, and simple reproducible builds.

**Not intended for:**
- Production-grade benchmarking (no CPU pinning, no statistical analysis, no perf counters).
- Extremely large brute-force runs (the $O(n^2)$ implementation is intentionally limited to reasonable sizes in the benchmark).

## 3. Inputs / Outputs

| Aspect | Details |
|--------|---------|
| **Input(s)** | `std::vector<int>` and `int target` (in library functions) |
| **Output(s)** | `std::vector<int>` containing `{i, j}` if found, otherwise `{}` |
| **Execution environment** | Cross-platform CLI; built with CMake; CI uses Ubuntu GitHub Actions runner |

## 4. Success Criteria
- **Functional:** Both `twoSumArray` and `twoSumHashTable` return correct indices for required test cases.
- **Quality:** Clean build with CMake, unit tests pass locally and in CI, code remains simple and maintainable.

## 5. Constraints
- **Language:** C++20 (STL)
- **Build system:** CMake (minimum 3.20)
- **Time/Scope:** Small educational project; focus on correctness, unit tests, and basic performance comparison.
- **Dependencies:** Only GoogleTest for unit tests (via CMake FetchContent).

## 6. Risks & Assumptions
- **Key assumptions:** There is at most one intended solution for the canonical examples; tests validate correctness rather than returning a specific pair for all possible multi-solution inputs.
- **Main risks:** Benchmark results can vary across machines; `unordered_map` has worst-case $O(n^2)$ behavior under adversarial hashing.
- **Mitigations:** Use a fixed RNG seed and report results as informational; keep benchmarks modest and clearly labeled.
