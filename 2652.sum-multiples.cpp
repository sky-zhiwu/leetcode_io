/*
 * @lc app=leetcode.cn id=2652 lang=cpp
 * @lcpr version=30102
 *
 * [2652] 倍数求和
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
    int sumOfMultiples(int n) {
        function<int(int, int)> f = [&] (int n, int m) {
            return ((m * (n / m) * (1 + n / m)) / 2);
        };
        return f(n, 3) + f(n, 5) + f(n, 7) - f(n, 15) - f(n, 21) - f(n, 35) + f(n, 105);
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

 */

