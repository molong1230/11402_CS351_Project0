
# Deploy / Build & Run Guide

This project is a CMake-based C++ project and does not require a runtime “deployment” step beyond building the binaries.

## Prerequisites

- CMake 3.20+
- A C++20 compiler (GCC/Clang/MSVC)
- Git (for fetching GoogleTest via `FetchContent`)

## Local Build (Release)

From the repository root:

1. Configure:
	 - `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`
2. Build:
	 - `cmake --build build --config Release`

## Run

- Example:
	- `./build/TwoSumApp`

- Unit tests:
	- `ctest --test-dir build --output-on-failure`

- Benchmark:
	- `./build/TwoSumBenchmark`

## CI (GitHub Actions)

The workflow `.github/workflows/build-and-test.yml` runs automatically on `push` and `pull_request`.

CI steps:
- Configure + build with CMake
- Run all tests using `ctest`

## Docker

Build a container image (tests run during the image build):

1. Build:
	- `docker build -t twosum-project .`
2. Run the example app:
	- `docker run --rm twosum-project`
3. Run the benchmark:
	- `docker run --rm twosum-project ./build/TwoSumBenchmark`

The Dockerfile uses Ubuntu 24.04, installs CMake and build tools, then runs `cmake`, `cmake --build`, and `ctest` in a single build step.

## Artifacts

No artifacts are uploaded by default.
If needed later, artifacts can be added (e.g., test logs) as a workflow enhancement.

