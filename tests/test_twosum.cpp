#include "twosum.hpp"
#include "twosum_cases.hpp"

#include <gtest/gtest.h>

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

TEST(TwoSumArray, Case1) {
    const auto& tc = getTwoSumCases().at(0);
    const auto answer = twoSumArray(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumArray, Case2) {
    const auto& tc = getTwoSumCases().at(1);
    const auto answer = twoSumArray(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumArray, Case3) {
    const auto& tc = getTwoSumCases().at(2);
    const auto answer = twoSumArray(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumArray, Case4) {
    const auto& tc = getTwoSumCases().at(3);
    const auto answer = twoSumArray(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumArray, Case5) {
    const auto& tc = getTwoSumCases().at(4);
    const auto answer = twoSumArray(tc.nums, tc.target);
    SCOPED_TRACE(::testing::Message() << "nums=" << vectorToString(tc.nums) << ", target=" << tc.target
                                      << ", answer=" << vectorToString(answer));
    EXPECT_TRUE(answer.empty()) << "Expected empty answer";
}

TEST(TwoSumHashTable, Case1) {
    const auto& tc = getTwoSumCases().at(0);
    const auto answer = twoSumHashTable(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumHashTable, Case2) {
    const auto& tc = getTwoSumCases().at(1);
    const auto answer = twoSumHashTable(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumHashTable, Case3) {
    const auto& tc = getTwoSumCases().at(2);
    const auto answer = twoSumHashTable(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumHashTable, Case4) {
    const auto& tc = getTwoSumCases().at(3);
    const auto answer = twoSumHashTable(tc.nums, tc.target);
    expectValidAnswer(tc.nums, tc.target, answer);
    EXPECT_EQ(answer, tc.expected);
}

TEST(TwoSumHashTable, Case5) {
    const auto& tc = getTwoSumCases().at(4);
    const auto answer = twoSumHashTable(tc.nums, tc.target);
    SCOPED_TRACE(::testing::Message() << "nums=" << vectorToString(tc.nums) << ", target=" << tc.target
                                      << ", answer=" << vectorToString(answer));
    EXPECT_TRUE(answer.empty()) << "Expected empty answer";
}
