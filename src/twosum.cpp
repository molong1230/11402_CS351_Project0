#include <vector>
#include <unordered_map>

using namespace std;

// 回傳兩個 index
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> map; // value -> index

    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end()) {
            return {map[complement], static_cast<int>(i)};
        }

        map[nums[i]] = static_cast<int>(i);
    }

    return {}; // 找不到
}