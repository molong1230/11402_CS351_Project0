# Two Sum (C++20)

本專案實作 Two Sum 的兩種解法，並提供單元測試、GitHub Actions CI，以及效能比較 benchmark。

## 專案結構

```
.
├── include/
│   └── twosum.hpp
├── src/
│   ├── main.cpp
│   ├── benchmark.cpp
│   └── twosum.cpp
├── tests/
│   └── test_twosum.cpp
├── CMakeLists.txt
└── .github/workflows/build-and-test.yml
```

## Required Functions

- `twoSumArray(const std::vector<int>& nums, int target)`
  - 暴力解，時間複雜度 $O(n^2)$
- `twoSumHashTable(const std::vector<int>& nums, int target)`
  - 雜湊表解，平均時間複雜度 $O(n)$

回傳值皆為 `std::vector<int>`：找到解則回傳 `{i, j}`，找不到回傳空 vector。

## Build & Run

### Build

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Run example app

```
./build/TwoSumApp
```

### Run tests

```
ctest --test-dir build --output-on-failure
```

### Run benchmark (performance comparison)

```
./build/TwoSumBenchmark
```

benchmark 會在可接受的輸入大小上同時跑 `twoSumArray` 與 `twoSumHashTable`，並另外提供一個更大的輸入只跑 hash-table 版，用來展示可擴展性。

## CI

GitHub Actions workflow 位於 `.github/workflows/build-and-test.yml`，會在 `push` 與 `pull_request` 時使用 CMake 建置並執行 `ctest`。

## Docker

建置映像檔時會自動編譯專案並執行單元測試（`ctest`）。若測試失敗，映像檔建置也會失敗。

```
docker build -t twosum-project .
docker run --rm twosum-project
```

執行 benchmark：

```
docker run --rm twosum-project ./build/TwoSumBenchmark
```

## Complexity Analysis

| 函式 | 時間複雜度 | 空間複雜度 |
|------|-----------|-----------|
| `twoSumArray` | $O(n^2)$ | $O(1)$ |
| `twoSumHashTable` | 平均 $O(n)$ | $O(n)$ |
