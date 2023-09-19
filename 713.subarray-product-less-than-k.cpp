/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=21913
 *
 * [713] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // 1 < nums[i] < 1000

        int n = nums.size(), pro = 1, cnt = 0;
        // 枚举右端点 同向双指针
        // 时间复杂度O(n) 空间复杂度O(1)
        int l = 0;
        for (int r = 0; r < n; r ++) {
            pro *= nums[r];
            while (pro >= k) {
                pro /= nums[l];
                l ++;
            }
            cnt += r - l + 1;
        }
        return cnt;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */

