/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=21913
 *
 * [213] 打家劫舍 II
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution {
public:
    int dfs(vector<int>&nums, int s, int e) {
        
        int f0 = 0, f1 = 0;
        for (int i = s; i < e; i ++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
    int rob(vector<int>& nums) {
        // 优化
        int n = nums.size();
        return max(nums[0] + dfs(nums, 2, n - 1), dfs(nums, 1, n));
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

