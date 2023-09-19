/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=21913
 *
 * [198] 打家劫舍
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
    int dfs(vector<int>&nums, int i, vector<int>& cache) {
        if (i < 0) return 0;
        if (cache[i] != -1) return cache[i];
        int res = max(dfs(nums, i - 1, cache), nums[i] + dfs(nums, i - 2, cache));
        cache[i] = res;
        return res;
    }
    int rob(vector<int>& nums) {
        // 从第一个或最后一个房子开始思考
        int n = nums.size();
        vector<int> cache(n, -1);
        return dfs(nums, n - 1, cache);

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

