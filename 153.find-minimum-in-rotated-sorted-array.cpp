/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=21913
 *
 * [153] 寻找旋转排序数组中的最小值
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
    int erfen(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n - 1;
        if (nums[r] > nums[l] || n == 1) return nums[l]; //旋转了n次

        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] >= nums[0]) l = mid + 1;
            else if (nums[mid - 1] > nums[mid]) return nums[mid];
            else r = mid - 1;
        }
        return nums[l];
    }
    int findMin(vector<int>& nums) {
        // return erfen(nums);
        
        // 红色表示最小值左侧，蓝色表示最小值及右侧
        //[0, n - 2] --> (-1, n - 1)
        int n = nums.size(), l = -1, r = n - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[n - 1]) r = mid;
            else l = mid; 
        }
        return nums[r];


    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */

