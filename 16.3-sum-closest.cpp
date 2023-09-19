/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=21913
 *
 * [16] 最接近的三数之和
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 1e6, n = nums.size(); //res>23000
        for (int i = 0; i < n - 2; i ++) {
            
            if (i > 0 && nums[i] == nums[i - 1] && i < n - 3) continue; //不算重复元素
            int l = i + 1, r = n - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                res = abs(s - target) < abs(res - target) ? s : res;
                // if (s == target) return target;
                if (s > target) {
                    
                    r --;
                    
                }else {
                    
                    l ++;
                    
                }
            }
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1]\n-14\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n-100\n
// @lcpr case=end

 */

