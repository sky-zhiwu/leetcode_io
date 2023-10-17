/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=21917
 *
 * [75] 颜色分类
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
    void quick_sort(vector<int>& nums, int l, int r) {
            if (l >= r) return;
            
            int i = l - 1, j = r + 1;
            int x = nums[l + r >> 1];
            while (i < j) {
                do (i ++); while (nums[i] < x);
                do (j --); while (nums[j] > x);
                if (i < j) swap(nums[i], nums[j]);
            }
            quick_sort(nums, l, j);
            quick_sort(nums, j + 1, r);
        }
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

