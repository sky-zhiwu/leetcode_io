/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=21913
 *
 * [209] 长度最小的子数组
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
#include<cmath>
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //同向双指针 时间复杂度O(n) 空间复杂度O(1)
        int sum = 0, n = nums.size();
        int cnt = n + 1;
        for (int r = 0, l = 0; r < n; r ++) {
            sum += nums[r];
            // if (sum >= target) {
            //     while (sum - nums[l] >= target) {
            //         sum -= nums[l];
            //         l ++;
            //     }
            //     cnt = min(cnt, r - l + 1);
            // }
            // 单调性
            while (sum >= target)
            {
                cnt = min(cnt, r - l + 1);
                sum -= nums[l];
                l ++;
            }
            
            
        }
        return cnt == n + 1 ? 0 : cnt ;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 15\n[1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

