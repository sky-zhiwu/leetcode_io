/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=21917
 *
 * [78] 子集
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
    /*回溯三问
    1.当前操作？选或不选当前的数字
    2.子问题？ 从>=i的部分构造子集
    3.下一个子问题？ >=i + 1的子集 dfs(i)->dfs(i + 1)*/

    vector<vector<int>> subsets(vector<int>& nums) {
        // 从输入分析
        /*vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                res.push_back(path);
                return ;
            }
            dfs(i + 1); // 不选，跳过，直接到i + 1
            path.push_back(nums[i]);
            dfs(i + 1);
            path.erase(path.end() - 1); // 恢复现场

        };
        dfs(0);
        return res;*/

        // 从答案分析
        /*回溯三问
        1.当前操作？枚举下标j >= i 的数字，加入path
        2.子问题？ 从>=i的部分构造子集
        3.下一个子问题？ >=j + 1的数字中构造子集 dfs(i)->dfs(i + 1/2/3/.../n)*/

        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        function<void(int)> dfs = [&] (int i) {
            res.push_back(path);
            if (i == n) { // 可省略
                return ;
            }
            for (int j = i; j < n; j ++) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.erase(path.end() - 1);
            }
        };
        dfs(0);
        return res;



    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

