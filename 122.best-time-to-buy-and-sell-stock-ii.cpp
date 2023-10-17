/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=21917
 *
 * [122] 买卖股票的最佳时机 II
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
        // int dp0 = 0, dp1 = -prices[0];
        // for (int i = 1; i < prices.size(); i ++) {
        //     int tmp = dp1; // 暂存前一天持有股票的最大利润
        //     dp1 = max(tmp, dp0 - prices[i]);
        //     dp0 = max(dp0, tmp + prices[i]);
        // }
        // return max(dp1, dp0);

        // 贪心
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i ++) {
            res += prices[i + 1] > prices[i] ? (prices[i + 1] - prices[i]) : 0;
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

