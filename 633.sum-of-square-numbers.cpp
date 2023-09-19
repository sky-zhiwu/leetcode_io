/*
 * @lc app=leetcode.cn id=633 lang=cpp
 * @lcpr version=21913
 *
 * [633] 平方数之和
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
#include<cmath>
// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;
        for (long long i = 0; i * i <= c / 2; i ++) {
            double b = sqrt(c - i * i);
            if (b == (int)b) return true;
            
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 100000\n
// @lcpr case=end

// @lcpr case=start
// 2147482647\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

