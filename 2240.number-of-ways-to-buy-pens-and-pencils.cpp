/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 * @lcpr version=21913
 *
 * [2240] 买钢笔和铅笔的方案数
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
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long sum = 0;
        for (int i = 0; cost1 * i <= total; i ++) {
            int j = (total - i * cost1) / cost2;
            sum += (j + 1); 
        }
        return sum;
    }
};  
// @lc code=end



/*
// @lcpr case=start
// 20\n10\n5\n
// @lcpr case=end

// @lcpr case=start
// 5\n10\n10\n
// @lcpr case=end

// @lcpr case=start
// 1000000\n1\n1\n
// @lcpr case=end

 */

