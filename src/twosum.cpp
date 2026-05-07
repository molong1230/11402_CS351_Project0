#include "twosum.hpp"

#include <unordered_map>

std::vector<int> twoSumArray(const std::vector<int>& nums, int target) {
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> value_to_index;
    value_to_index.reserve(nums.size());

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        const int complement = target - nums[i];

        const auto it = value_to_index.find(complement);
        if (it != value_to_index.end()) {
            return {it->second, i};
        }

        // Keep the earliest index for a value (simplifies duplicate handling).
        if (!value_to_index.contains(nums[i])) {
            value_to_index.emplace(nums[i], i);
        }
    }

    return {};
}
