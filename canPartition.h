#pragma once
#include <vector>

bool canPartition(std::vector<int>& nums, bool rec);

    // recursive solution times out //
    bool recur(std::vector<int>& nums, int starting_index, int target);

    // dynamic programming solution
    bool dp(std::vector<int>& nums, int target);