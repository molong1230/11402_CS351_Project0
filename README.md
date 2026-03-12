# Two Sum


 * Finds two numbers in the array that add up to the target sum.
 * This function solves the classic Two Sum problem by identifying a pair of distinct elements
 * whose sum equals the specified target value.
 * 
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
    
