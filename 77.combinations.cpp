/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30102
 *
 * [77] 组合
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
    vector<vector<int>> combine(int n, int k) {
        /*剪枝技巧
          时间复杂度O(C(n, k) * k)
          空间复杂度O(k)
        */
        vector<vector<int>> ans;
        vector<int> path; //若为m，还需要k-m个数
        function<void(int )> dfs = [&] (int x) {// 从x到n中选
            int d = k - path.size(); // 还要选d个数
            // if (n - x + 1 < d) return ;
            if (path.size() == k) {
                ans.push_back(path);
                return ;
            }
            for (int j = x; j <= n + 1 - d; j ++) {
                path.push_back(j);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

