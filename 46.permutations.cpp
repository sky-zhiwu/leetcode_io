/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30105
 *
 * [46] 全排列
 */


// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        vector<bool> mask(n, false); 
        /*
            
        */
        function<void(int)> dfs = [&] (int idx) {
            if (path.size() == n) {
                ans.push_back(path);
                return;
            } 
            for (int j = 0; j < n; j ++) {
                if (!mask[j]) {
                    mask[j] = true;
                    path.push_back(nums[j]);
                    dfs(j);
                    path.pop_back();
                    mask[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

