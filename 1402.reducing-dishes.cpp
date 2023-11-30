/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 * @lcpr version=30102
 *
 * [1402] 做菜顺序
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int f = 0, s = 0;
        for (auto& x : satisfaction) {
            s += x;
            if (s <= 0) break;
            f += s;
        }
        return f;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,-8,0,5,-9]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-4,-5]\n
// @lcpr case=end

 */

