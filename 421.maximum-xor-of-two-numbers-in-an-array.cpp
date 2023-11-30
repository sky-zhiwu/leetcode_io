/*
 * @lc app=leetcode.cn id=421 lang=cpp
 * @lcpr version=30104
 *
 * [421] 数组中两个数的最大异或值
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
    int findMaximumXOR(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int high = mx ? _builtin_clz(mx) : -1;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,10,5,25,2,8]\n
// @lcpr case=end

// @lcpr case=start
// [14,70,53,83,49,91,36,80,92,51,66,70]\n
// @lcpr case=end

 */

