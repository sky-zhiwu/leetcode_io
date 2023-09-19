/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=21913
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        //时间复杂度O(n)
        //空间复杂度O(n)
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i ++) {
            //两个优化
            //1.如果当前元素和相邻元素相加>0，则不可能有等于0的三数存在（全都大于0
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;//之后也不可能再=0了
            //2.如果当前元素和最后两个元素相加<0，则不可能有等于0的三数存在（全都小于0
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;//后面可能还可以=0，num[i]变大

            if (i > 0 && nums[i] == nums[i - 1]) continue; //不能有重复的三元组

            int l = i + 1, r = n - 1;
            
            //相向双指针
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0) r --;
                else if (s == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l ++;
                    while (l < r && nums[l] == nums[l - 1]) l ++;
                    r --;
                    while (l < r && nums[r] == nums[r + 1]) r --;
                }
                else l ++;
                //跳过l和r相等的情况
                
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

