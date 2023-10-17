/*
 * @lc app=leetcode.cn id=714 lang=cpp
 * @lcpr version=21917
 *
 * [714] 买卖股票的最佳时机含手续费
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
    int maxProfit(vector<int>& prices, int fee) {
        int dp0 = -prices[0], dp1 = 0;
        for (int i = 1; i < prices.size(); i ++) {
            int t0 = dp0;
            dp0 = max(dp0, dp1 - prices[i]);
            dp1 = max(dp1, t0 + prices[i] - fee);
        }
        return max(dp1, dp0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 3, 2, 8, 4, 9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */

