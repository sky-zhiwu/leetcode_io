/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=21913
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};
        int n = nums.size() ;
        for (int i = 0; i < n - 3; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j ++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    // cout << " " << i << " " << " " << j << " " << " " << l << " " << " " << r << " ";
                    long long s ;
                    s = nums[i] + nums[j] ;
                    s += nums[l] ; s += nums[r];
                    // cout << " " << s << " ";
                    if (s > target) r --;
                    else if (s < target) l ++;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l ++;
                        while (l < r && nums[l] == nums[l - 1]) l ++;
                        r --;
                        while (l < r && nums[r] == nums[r + 1]) r --;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

// @lcpr case=start
// [1000000000,1000000000,1000000000,1000000000]\n0\n
// @lcpr case=end

 */

