/*
 * @lc app=leetcode.cn id=747 lang=cpp
 * @lcpr version=30102
 *
 * [747] 至少是其他数字两倍的最大数
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
    int dominantIndex(vector<int>& nums) {
        int m1 = -1, m2 = -1, idx = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                idx = i;
            }
            else if (nums[i] > m2) m2 = nums[i];
        }
        return m2 * 2 > m1 ? -1 : idx; 

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

