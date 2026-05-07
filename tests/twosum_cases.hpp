#pragma once

#include <vector>

struct TwoSumCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
};

inline const std::vector<TwoSumCase>& getTwoSumCases() {
    static const std::vector<TwoSumCase> kCases{
        TwoSumCase{{2, 7, 11, 15}, 9, {0, 1}},
        TwoSumCase{{-1, -2, -3, -4, -5}, -8, {2, 4}},
        TwoSumCase{{3, 3}, 6, {0, 1}},
        TwoSumCase{{0, 4, 3, 0}, 0, {0, 3}},
        TwoSumCase{{1}, 2, {}},
    };
    return kCases;
}
