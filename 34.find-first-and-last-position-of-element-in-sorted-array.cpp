/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=21913
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    // int search1(vector<int>& nums, int target) {
    //     int l = 0, r = nums.size() - 1;
    //     while (l < r) {
    //         // int mid = 
    //     }
    // }

    int erfen(vector<int>& nums, int target) { // 闭区间[l, r]
        int l = 0, r = nums.size() - 1; 
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        int start = erfen(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        int end = erfen(nums, target + 1) - 1;

        return {start, end};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

