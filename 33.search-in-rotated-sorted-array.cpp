/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=21913
 *
 * [33] 搜索旋转排序数组
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
    bool is_blue(vector<int>& nums, int target, int idx) {
        int end = nums.size() - 1;
        if (nums[idx] > nums[end]) 
            return (target <= nums[idx] && target > nums[end]);
        else 
            return (target <= nums[idx] || target > nums[end]);
    }

    int search(vector<int>& nums, int target) {
        // int l = 0, n = nums.size(), r = n - 1;
        // if (n == 1) return nums[0] == target ? 0 : -1;

        // while (l <= r) { //[l, mid] [mid + 1, r]
        //     int mid = l + r >> 1;
        //     if (target == nums[mid]) return mid;
        //     if (target >= nums[0]) {
        //         if (nums[mid] >= nums[0] && nums[mid] < target) l = mid + 1;
        //         else r = mid - 1;
        //     }
        //     else {
        //         if (nums[mid] < nums[0] && nums[mid] > target) r = mid - 1;
        //         else l = mid + 1;
        //     }
        // }
        // if (l == n || nums[l] != target) return -1;
        // return l;

        //红蓝染色 红为目标值左边 蓝为右边
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (is_blue(nums, target, mid)) r = mid - 1;
            else l = mid + 1;
        }
        if (l == n || nums[l] != target) return -1;
        return l;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1, 3, 5]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,8,1,2,3]\n8\n
// @lcpr case=end


 */

