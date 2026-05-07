#include "twosum_cases.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {

std::string numsToParenString(const std::vector<int>& nums) {
    std::ostringstream oss;
    oss << "(";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i != 0) {
            oss << ",";
        }
        oss << nums[i];
    }
    oss << ")";
    return oss.str();
}

} // namespace

int main() {
    const auto& cases = getTwoSumCases();

    const std::vector<std::string> algos{"array", "hashtable"};

    size_t leftWidth = 0;
    size_t numsWidth = 0;

    for (size_t i = 0; i < cases.size(); ++i) {
        for (const auto& algo : algos) {
            const std::string left = "case" + std::to_string(i + 1) + " - " + algo;
            leftWidth = std::max(leftWidth, left.size());

            const std::string numsStr = numsToParenString(cases[i].nums);
            numsWidth = std::max(numsWidth, numsStr.size());
        }
    }

    for (size_t i = 0; i < cases.size(); ++i) {
        const auto& tc = cases[i];
        const std::string numsStr = numsToParenString(tc.nums);

        for (const auto& algo : algos) {
            const std::string left = "case" + std::to_string(i + 1) + " - " + algo;

            std::cout << left;
            if (left.size() < leftWidth) {
                std::cout << std::string(leftWidth - left.size(), ' ');
            }
            std::cout << "  " << numsStr;
            if (numsStr.size() < numsWidth) {
                std::cout << std::string(numsWidth - numsStr.size(), ' ');
            }
            std::cout << " target:" << tc.target << "\n";
        }
    }

    return 0;
}
