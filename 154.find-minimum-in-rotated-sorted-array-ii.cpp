/*
 * @lc app=leetcode.cn id=154 lang=cpp
 * @lcpr version=21913
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
    int is_blue(vector<int>& nums, int idx) {
        int end = nums.size() - 1;
        if (nums[idx] > nums[end]) 
            return 0; //0代表是红色
        else if (nums[idx] == nums[end]) {
            int i = idx - 1;
            while (i >= 0) {
                if (nums[i] == nums[end]) i --;
                else break;
            }
            return i == -1 ? 0 : 2;
        }
        else return 2; // 2代表是蓝色
    }
    int findMin(vector<int>& nums) {
        
        int l = -1, n = nums.size(), r = n;
        if (n == 1) return nums[0];
        while (l + 1 < r) {
            int mid = l + r >> 1;
            // cout << " " << mid << "\n";
            if (is_blue(nums, mid) == 0) l = mid;
            else r = mid;
        }
        return r == n ? nums[r - 1] : nums[r];

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,0,1]\n
// @lcpr case=end

 */

