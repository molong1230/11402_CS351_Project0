#include "twosum.hpp"

#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace {

struct BenchmarkCase {
    std::vector<int> nums;
    int target;
};

BenchmarkCase makeCase(std::size_t n, std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(-1'000'000'000, 1'000'000'000);

    BenchmarkCase c;
    c.nums.resize(n);
    for (std::size_t i = 0; i < n; ++i) {
        c.nums[i] = dist(rng);
    }

    if (n >= 2) {
        // Force at least one valid solution near the end.
        const int a = 1234567;
        const int b = 7654321;
        c.nums[n - 2] = a;
        c.nums[n - 1] = b;
        c.target = a + b;
    } else {
        c.target = 0;
    }

    return c;
}

template <typename Func>
std::chrono::nanoseconds timeCase(const BenchmarkCase& c, int iterations, Func func, std::uint64_t& checksum) {
    const auto start = std::chrono::steady_clock::now();
    for (int it = 0; it < iterations; ++it) {
        const auto ans = func(c.nums, c.target);
        checksum += static_cast<std::uint64_t>(ans.size());
        if (ans.size() == 2) {
            checksum += static_cast<std::uint64_t>(ans[0]);
            checksum += static_cast<std::uint64_t>(ans[1]);
        }
    }
    const auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

void runAndPrint(const std::string& label, const BenchmarkCase& c, int iterations, bool runArray, bool runHash) {
    std::uint64_t checksum = 0;

    std::cout << "\n== " << label << " ==\n";
    std::cout << "n=" << c.nums.size() << ", iterations=" << iterations << "\n";

    if (runArray) {
        const auto elapsed = timeCase(c, iterations, twoSumArray, checksum);
        const double ms = elapsed.count() / 1'000'000.0;
        std::cout << "twoSumArray     : " << std::fixed << std::setprecision(3) << ms << " ms total\n";
    }

    if (runHash) {
        const auto elapsed = timeCase(c, iterations, twoSumHashTable, checksum);
        const double ms = elapsed.count() / 1'000'000.0;
        std::cout << "twoSumHashTable : " << std::fixed << std::setprecision(3) << ms << " ms total\n";
    }

    // Prevent dead-code elimination.
    std::cout << "checksum=" << checksum << "\n";
}

} // namespace

int main() {
    std::mt19937 rng(12345);

    // Sizes where O(n^2) is still reasonable.
    const BenchmarkCase small = makeCase(2'000, rng);
    const BenchmarkCase medium = makeCase(5'000, rng);

    // Large case for demonstrating hash-table scalability.
    const BenchmarkCase large = makeCase(200'000, rng);

    runAndPrint("Small (both)", small, 200, /*runArray=*/true, /*runHash=*/true);
    runAndPrint("Medium (both)", medium, 50, /*runArray=*/true, /*runHash=*/true);
    runAndPrint("Large (hash only)", large, 20, /*runArray=*/false, /*runHash=*/true);

    return 0;
}
