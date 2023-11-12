#pragma once

#include "canPartition.h"
#include <algorithm>
#include <numeric>


bool canPartition(std::vector<int>& nums, bool rec) {
        int target = std::accumulate(nums.begin(), nums.end(), 0);

        // if target is odd, this is impossible
        if (target % 2 != 0) {
            return false;
        }
        if (rec) {
            return recur(nums, 0, target / 2);
        }
        return dp(nums, target / 2);
    }

    // recursive solution times out //
    bool recur(std::vector<int>& nums, int starting_index, int target) {
        // base case
        if (target == 0) {
            return true;
        } else if (target < 0 || starting_index == nums.size()) {
            return false;
        }
        
        return recur(nums, starting_index + 1, target) || 
            recur(nums, starting_index + 1, target - nums.at(starting_index));
    }

    // dynamic programming solution
    bool dp(std::vector<int>& nums, int target) {
        bool memo[target + 1];
        std::fill_n(memo, target + 1, 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int value = nums.at(i);
            if (value == target) {
                return true;
            }
            if (value > target) {
                return false;
            }
            for (int m_i = target - value; m_i >= 0; --m_i) {
                if (memo[m_i] && value + m_i == target) {
                    return true;
                }
                if (!memo[value + m_i]) {
                    memo[value + m_i] = memo[m_i] && true;
                }
            }
            memo[value] = true;
        }
        return false;
    }