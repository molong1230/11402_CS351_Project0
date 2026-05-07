#include "twosum.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <vector>

namespace {

std::string vectorToString(const std::vector<int>& values) {
    std::ostringstream oss;
    oss << "{";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            oss << ", ";
        }
        oss << values[i];
    }
    oss << "}";
    return oss.str();
}

void printCase(const std::vector<int>& nums, int target) {
    std::cout << "[case] nums=" << vectorToString(nums) << " target=" << target << "\n";
}

void expectValidAnswer(const std::vector<int>& nums, int target, const std::vector<int>& answer) {
    SCOPED_TRACE(::testing::Message() << "nums=" << vectorToString(nums) << ", target=" << target
                                      << ", answer=" << vectorToString(answer));

    if (answer.empty()) {
        FAIL() << "Expected a non-empty answer";
    }
    ASSERT_EQ(answer.size(), 2u);

    const int i = answer[0];
    const int j = answer[1];

    ASSERT_GE(i, 0);
    ASSERT_GE(j, 0);
    ASSERT_LT(i, static_cast<int>(nums.size()));
    ASSERT_LT(j, static_cast<int>(nums.size()));
    ASSERT_NE(i, j);

    EXPECT_EQ(nums[i] + nums[j], target);
}

} // namespace

TEST(TwoSumArray, BasicExample) {
    const std::vector<int> nums{2, 7, 11, 15};
    const int target = 9;
    printCase(nums, target);

    const auto answer = twoSumArray(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{0, 1}));
}

TEST(TwoSumHashTable, BasicExample) {
    const std::vector<int> nums{2, 7, 11, 15};
    const int target = 9;
    printCase(nums, target);

    const auto answer = twoSumHashTable(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{0, 1}));
}

TEST(TwoSumArray, NegativeNumbers) {
    const std::vector<int> nums{-1, -2, -3, -4, -5};
    const int target = -8;
    printCase(nums, target);

    const auto answer = twoSumArray(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{2, 4}));
}

TEST(TwoSumHashTable, NegativeNumbers) {
    const std::vector<int> nums{-1, -2, -3, -4, -5};
    const int target = -8;
    printCase(nums, target);

    const auto answer = twoSumHashTable(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{2, 4}));
}

TEST(TwoSumArray, DuplicateValues) {
    const std::vector<int> nums{3, 3};
    const int target = 6;
    printCase(nums, target);

    const auto answer = twoSumArray(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{0, 1}));
}

TEST(TwoSumHashTable, DuplicateValues) {
    const std::vector<int> nums{3, 3};
    const int target = 6;
    printCase(nums, target);

    const auto answer = twoSumHashTable(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{0, 1}));
}

TEST(TwoSumArray, ZeroInSolution) {
    const std::vector<int> nums{0, 4, 3, 0};
    const int target = 0;
    printCase(nums, target);

    const auto answer = twoSumArray(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{0, 3}));
}

TEST(TwoSumHashTable, ZeroInSolution) {
    const std::vector<int> nums{0, 4, 3, 0};
    const int target = 0;
    printCase(nums, target);

    const auto answer = twoSumHashTable(nums, target);
    expectValidAnswer(nums, target, answer);
    EXPECT_EQ(answer, (std::vector<int>{0, 3}));
}

TEST(TwoSumArray, SmallInputNoSolution) {
    const std::vector<int> nums{1};
    const int target = 2;
    printCase(nums, target);

    const auto answer = twoSumArray(nums, target);
    SCOPED_TRACE(::testing::Message() << "nums=" << vectorToString(nums) << ", target=" << target
                                      << ", answer=" << vectorToString(answer));
    EXPECT_TRUE(answer.empty()) << "Expected empty answer";
}

TEST(TwoSumHashTable, SmallInputNoSolution) {
    const std::vector<int> nums{1};
    const int target = 2;
    printCase(nums, target);

    const auto answer = twoSumHashTable(nums, target);
    SCOPED_TRACE(::testing::Message() << "nums=" << vectorToString(nums) << ", target=" << target
                                      << ", answer=" << vectorToString(answer));
    EXPECT_TRUE(answer.empty()) << "Expected empty answer";
}
