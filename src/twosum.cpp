#include <vector>
#include <unordered_map>

using namespace std;

// 使用 O(n^2) 陣列解法，回傳兩個 index
vector<int> TwoSumArray(vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // 找不到
}

// 使用 hash table 解法，回傳兩個 index
vector<int> TwoSumHashTable(vector<int>& nums, int target) {
    unordered_map<int, int> map; // value -> index

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int complement = target - nums[i];

        auto it = map.find(complement);
        if (it != map.end()) {
            return {it->second, i};
        }

        map[nums[i]] = i;
    }

    return {}; // 找不到
}

// 保留原本的介面，預設使用 hash table 解法
vector<int> twoSum(vector<int>& nums, int target) {
    return TwoSumHashTable(nums, target);
}