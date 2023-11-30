/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30102
 *
 * [746] 使用最小花费爬楼梯
 */


// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int dp[1001], n = cost.size();
        // dp[0] = 0, dp[1] = 0;
        // for (int i = 2; i <= n; i ++) 
        //     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        // return dp[n];
        int f0 = 0, f1 = 0, n = cost.size();
        for (int i = 2; i <= n; i ++) {
            int new_f = min(f1 + cost[i - 1], f0 + cost[i - 2]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */

