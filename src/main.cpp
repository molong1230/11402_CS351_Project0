#include <iostream>
#include <vector>

using namespace std;

// 宣告 function（因為在另一個檔案）
vector<int> twoSum(const vector<int>& nums, int target);

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Index: " << result[0] << ", " << result[1] << endl;
        cout << "Value: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}