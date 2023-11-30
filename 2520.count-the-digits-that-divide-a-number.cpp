/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 * @lcpr version=30102
 *
 * [2520] 统计能整除数字的位数
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
    int countDigits(int num) {
        int ans = 0, x = num;
        while (x) {
            ans += (num % (x % 10) == 0);
            x /= 10;
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// 1248\n
// @lcpr case=end

 */

