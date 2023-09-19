/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 * @lcpr version=21913
 *
 * [1237] 找出给定方程的正整数解
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
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int x = 1, y = 1; customfunction.f(x, y) <= z; x ++) {
            int l = 1, r = z; //y在1和z之间
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (customfunction.f(x, mid) == z) {
                    res.push_back({x, mid});
                    break;
                }
                else if (customfunction.f(x, mid) < z) l = mid  + 1;
                else r = mid - 1;
            }

        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n5\n
// @lcpr case=end

// @lcpr case=start
// 2\n5\n
// @lcpr case=end

 */

