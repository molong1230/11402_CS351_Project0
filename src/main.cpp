#include "twosum.hpp"

#include <iostream>
#include <vector>

int main() {
    const std::vector<int> nums = {2, 7, 11, 15};
    const int target = 9;

    const std::vector<int> result = twoSumHashTable(nums, target);

    if (result.size() == 2) {
        std::cout << "Index: " << result[0] << ", " << result[1] << "\n";
        std::cout << "Value: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << "\n";
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}