/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30102
 *
 * [216] 组合总和 III
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
    vector<vector<int>> combinationSum3(int k, int n) {
        /*剪枝
          剩余数字数目不够 i < d
          target < 0
          剩余数字即使选最大的，和也不能达到t（等差数列求和 i到i-d+1）
          */
        vector<vector<int>> ans;
        vector<int> path; 
        function<void(int, int)> dfs = [&] (int x, int t) {// 从x到9中选，和为t
            int d = k - path.size(); // 还要选d个数
            if (10 - x < d) return ;
            if (t < 0 || (t > (19 - d) * d / 2)) return ;
            if (path.size() == k) {
                ans.push_back(path);
                return ;
            }
            for (int j = x; j <= 10 - d; j ++) {
                path.push_back(j);
                dfs(j + 1, t - j);
                path.pop_back();
            }
        };
        dfs(1, n);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

