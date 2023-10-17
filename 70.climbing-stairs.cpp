/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=21917
 *
 * [70] 爬楼梯
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
    int climbStairs(int n) {
        if (n == 1) return 1;

        int p = 1, q = 1, r = 2;
        for (int i = 2; i < n; i ++) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

