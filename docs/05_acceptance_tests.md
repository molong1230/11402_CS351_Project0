
# Acceptance Tests

These are high-level checks to consider the project acceptable.

## AT-1: Build succeeds (Release)

Steps:
1. Configure: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`
2. Build: `cmake --build build --config Release`

Expected result:
- Build completes successfully.
- `TwoSumApp`, `TwoSumTest`, and `TwoSumBenchmark` are produced.

## AT-2: Unit tests pass

Steps:
1. Run: `ctest --test-dir build --output-on-failure`

Expected result:
- All tests pass.

## AT-3: Example program runs

Steps:
1. Run: `./build/TwoSumApp`

Expected result:
- Program prints a valid pair of indices and values for the hard-coded example.

## AT-4: Benchmark runs

Steps:
1. Run: `./build/TwoSumBenchmark`

Expected result:
- Program prints timing lines for `twoSumArray` and `twoSumHashTable` on small/medium cases.
- Program prints timing for hash-table on a large case.

## AT-5: CI passes on GitHub

Steps:
1. Push changes to GitHub, or open a Pull Request.
2. Check the GitHub Actions run for `build-and-test`.

Expected result:
- Workflow completes successfully and shows a green status.

## AT-6: Docker build runs tests

Steps:
1. Build: `docker build -t twosum-project .`
2. Run: `docker run --rm twosum-project`

Expected result:
- Docker build completes successfully (unit tests pass during build).
- Container prints a valid pair of indices and values for the hard-coded example.

