#include <vector>
#include <unordered_map>

using namespace std;

// 回傳兩個 index
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }

        map[nums[i]] = i;
    }

    return {}; // 找不到
}