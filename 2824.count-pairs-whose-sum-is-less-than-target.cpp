/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 * @lcpr version=21913
 *
 * [2824] 统计和小于目标的下标对数目
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
    int countPairs(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        if (n == 1) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        if (nums[r] + nums[r - 1] < target) return n * (n - 1) / 2;
        // 滑动窗口??
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                ans += r - l;
                l ++;
            }
            else r --;
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,1,2,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-6,2,5,-2,-7,-1,3]\n-2\n
// @lcpr case=end

 */

