/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=21913
 *
 * [1658] 将 x 减到 0 的最小操作数
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
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        if (nums[0] > x && nums[n - 1] > x) return -1;

        for (int m : nums) sum += m;
        if (sum < x) return -1;

        int cnt = n, l = 0;
        for (int r = 0; r < n; r ++) {
            sum -= nums[r];
            while (sum <= x && l <= r) {
                if (sum == x) {
                    cnt = min(cnt, n - r + l - 1);
                }
                sum += nums[l++];
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */

