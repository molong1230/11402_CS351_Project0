# Project 0 — Two Sum (C++20)

**CS351 AI 輔助軟體開發** · 元智大學資工系 · 黃士弦（s1113344）

在整數陣列中找出兩個索引，使其元素和等於目標值。本專案實作暴力法與雜湊表兩種解法，並以單元測試、CI、benchmark 與 Docker 驗證正確性與效能差異。

## 相關連結

| 項目 | 網址 |
|------|------|
| 課程總 repo | https://github.com/molong1230/11402_CS351 |
| 個人網站 | https://molong1230.github.io/ |
| Project B | https://github.com/molong1230/11402_CS351_ProjectB |
| GitHub Actions | https://github.com/molong1230/11402_CS351_Project0/actions |

## 專案目標

- 實作 `twoSumArray`（暴力 O(n²)）與 `twoSumHashTable`（雜湊表平均 O(n)）
- 以 GoogleTest + `ctest` 覆蓋一般、負數、重複、無解等案例
- 透過 benchmark 比較兩種解法在不同輸入規模下的耗時
- 以 GitHub Actions 在每次 push / PR 時自動建置與測試

## 演算法說明

| 函式 | 作法 | 時間 | 空間 |
|------|------|------|------|
| `twoSumArray` | 雙層迴圈枚舉所有索引對 | O(n²) | O(1) |
| `twoSumHashTable` | 遍歷時以 hash map 記錄「值 → 索引」 | 平均 O(n) | O(n) |

回傳型別為 `std::vector<int>`：找到解回傳 `{i, j}`（`i < j`），否則回傳空 vector。

## 專案結構

```
.
├── include/twosum.hpp      # 介面宣告
├── src/
│   ├── twosum.cpp          # 演算法實作
│   ├── main.cpp            # TwoSumApp 範例
│   └── benchmark.cpp       # TwoSumBenchmark
├── tests/test_twosum.cpp   # 單元測試
├── docs/                   # SRS、SDS、測試計畫等（見下方文件索引）
├── CMakeLists.txt
├── Dockerfile
└── .github/workflows/build-and-test.yml
```

## 建置與執行

### 前置需求

- C++20 編譯器（g++ / clang++ / MSVC）
- CMake 3.16+

### Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### 執行範例程式

```bash
./build/TwoSumApp
```

Windows PowerShell：

```powershell
.\build\TwoSumApp.exe
```

### 執行測試

```bash
ctest --test-dir build --output-on-failure
```

### 執行 benchmark

```bash
./build/TwoSumBenchmark
```

benchmark 會在可接受的輸入大小上同時比較 `twoSumArray` 與 `twoSumHashTable`，並以較大輸入單獨展示 hash 版的可擴展性。

## CI / Docker

- **CI：** `.github/workflows/build-and-test.yml` 於 `push`、`pull_request` 時建置並執行 `ctest`
- **Docker：** 建置映像時會編譯並跑測試，失敗則映像建置失敗

```bash
docker build -t twosum-project .
docker run --rm twosum-project
docker run --rm twosum-project ./build/TwoSumBenchmark
```

## 開發歷程（摘要）

| 階段 | 內容 |
|------|------|
| M1 | CMake 專案骨架、`twosum` 函式庫與執行檔目標 |
| M2 | 暴力解與雜湊表解法實作 |
| M3 | GoogleTest 單元測試（含邊界與無解案例） |
| M4 | GitHub Actions 自動化 CI |
| M5 | Benchmark 效能比較（固定亂數種子） |
| M6 | Dockerfile 建置即測試 |

詳細里程碑見 [`docs/01_plan.md`](docs/01_plan.md)。

## 測試重點

- 基本有效解、負數、重複值、含 0 的解
- 小輸入與無解情境
- CI 與 Docker 建置流程確保每次提交可重現建置結果

## 文件索引（`docs/`）

| 文件 | 說明 |
|------|------|
| [00_intended_use.md](docs/00_intended_use.md) | 問題定義與成功準則 |
| [01_plan.md](docs/01_plan.md) | 實作計畫與里程碑 |
| [02_SRS.md](docs/02_SRS.md) | 軟體需求規格 |
| [03_SDS.md](docs/03_SDS.md) | 軟體設計規格 |
| [04_test_plan.md](docs/04_test_plan.md) | 測試與 benchmark 策略 |
| [05_acceptance_tests.md](docs/05_acceptance_tests.md) | 驗收測試 |
| [06_traceability.md](docs/06_traceability.md) | 需求追溯 |
| [07_deploy.md](docs/07_deploy.md) | 建置與部署 |
| [08_known_issues.md](docs/08_known_issues.md) | 已知限制 |

## 複雜度分析

| 函式 | 時間複雜度 | 空間複雜度 |
|------|-----------|-----------|
| `twoSumArray` | O(n²) | O(1) |
| `twoSumHashTable` | 平均 O(n) | O(n) |

---

課程作業用途 · [molong1230](https://github.com/molong1230)
