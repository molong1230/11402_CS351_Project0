#pragma once

#include <vector>

// Brute-force O(n^2) solution.
// Returns {i, j} such that nums[i] + nums[j] == target, or {} if not found.
std::vector<int> twoSumArray(const std::vector<int>& nums, int target);

// Hash-table O(n) average-time solution.
// Returns {i, j} such that nums[i] + nums[j] == target, or {} if not found.
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);
