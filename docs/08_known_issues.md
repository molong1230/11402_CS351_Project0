
# Known Issues / Limitations

## 1. Benchmark variability

The benchmark is intended for educational comparison only.
Timing results vary depending on CPU, OS, power settings, and background load.

## 2. Brute force scalability

`twoSumArray` is $O(n^2)$ and becomes impractical for very large `n`.
The benchmark avoids running brute force at huge sizes by design.

## 3. Hash-table worst-case

`twoSumHashTable` uses `std::unordered_map`.
Average performance is $O(n)$, but worst-case performance can degrade under extreme hash collision scenarios.

## 4. Multiple valid answers

Some inputs may have multiple valid index pairs.
The functions return the first pair found under their traversal strategy.
Unit tests assert exact indices only for canonical examples where the answer is unambiguous.

