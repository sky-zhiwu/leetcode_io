/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=21917
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit(vector<int>& prices) {
        int dp0 = 0, dp1 = 0, dp2 = -prices[0];

        // dp0表示当天不持有股票且当天没卖出
        //dp1表示当天不持有但是当天卖出
        //dp2表示当天持有股票
        
        for (int i = 1; i < prices.size(); i ++) {
            int t0 = dp0;
            dp0 = max(dp1, dp0);
            dp1 = dp2 + prices[i];
            dp2 = max(dp2, t0 - prices[i]);
        }
        return max(dp0, dp1);

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

