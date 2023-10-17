/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=21917
 *
 * [96] 不同的二叉搜索树
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
    int res = 0;
    int help(int start, int end) {
        if (start > end) return 0;
        for (int i = start; i <= end; i ++) {
            int l = help(start, i - 1), r = help(i + 1, end);
            res += l + r;
        }
        return res;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < n + 1; i ++) {
            for (int j = 1; j < i + 1; j ++) {
                dp[i] += dp[j - 1] * dp[i - j]; //这里i相当于不同的n
            }
        }

        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

