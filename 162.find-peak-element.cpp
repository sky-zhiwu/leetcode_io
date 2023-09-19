/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=21913
 *
 * [162] 寻找峰值
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
        cout << " " << n << "\n";
        while (l <= r) { //左闭右闭
            int mid = l + r >> 1;
            // cout << " " << mid << "\n";
            if (nums[mid  - 1] <= nums[mid] && nums[mid] >= nums[mid + 1]) return mid - 1;
            if (nums[mid  - 1] <= nums[mid] && nums[mid] <= nums[mid + 1]) l = mid + 1;
            else r = mid;
            
        }
        return l - 1;
    }
    int findPeakElement(vector<int>& nums) {
        // nums.insert(nums.begin(), INT_MIN);
        // nums.push_back(INT_MIN);
        // int res = erfen(nums);
        // return res;
        
        //[0, n - 2] --> (-1, n - 1) --> (l, mid) & (mid, r)
        //红蓝染色法 红色是峰顶之前的数 蓝色是峰顶及之后的数
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[mid + 1]) l = mid;
            else r = mid;
        }
        return r;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */

