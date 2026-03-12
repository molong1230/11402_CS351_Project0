# Two Sum


 * Finds two numbers in the array that add up to the target sum.
 * This function solves the classic Two Sum problem by identifying a pair of distinct elements
 * whose sum equals the specified target value.
 
 * @param {number[]} nums - Array of integers to search through
 * @param {number} target - The target sum value to find
 * @returns {number[]} Array containing the indices of the two numbers that add up to target
 

 ## Requirements


 - Use **C++20** as the implementation language.
 - Use **`std::vector<int>`** for the input array and result storage.

 - Provide two solution implementations:
    - **`TwoSumArray`**: a direct array-based approach.
    - **`TwoSumHashTable`**: a hash-table-based approach using the STL.

 - Each implementation should:
    - accept an integer array and a target value,
    - return the indices of the two maching elements,
    - avoid using the same element twice.

 - Include test cases for:
    - a basic valid example,
    - negative numbers,
    - duplicate values,
    - zero as part of the solution,
    - small input sizes.

 - Add **GitHub Actions** to automatically:
    - build the project,
    - run all test cases,
    - trigger on `push` and `pull_request`.

 - Add **Docker** support to :
    - build the C++ project in a reproducible environment,
    - run the test suite inside a container.
    

## Detail about GitHub Actions

- Create a `.github/workflows/build-and-test.yml` file in your repository root.
- Define the workflow to trigger on `push` and `pull_request` events.
- Use `ubuntu-latest` as the runner environment.
- Add steps to:
    - Checkout the repository code using `actions/checkout@v3`.
    - Install C++20 compiler and build tools (`g++-11` or `clang++-14`).
    - Install CMake for project configuration.
    - Configure the project with `cmake -B build`.
    - Build the project with `cmake --build build`.
    - Run test cases with `./build/TwoSumTest` or equivalent test executable.
- Set the workflow to fail if any step returns a non-zero exit code.
- Optionally add a step to upload test results or coverage reports as artifacts.