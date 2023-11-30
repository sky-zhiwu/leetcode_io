/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30102
 *
 * [22] 括号生成
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
    vector<string> generateParenthesis(int n) {
        /*回溯三问
        当前操作：枚举path[i]为'('还是')'
        子问题：构造path>=i的部分
        下一个子问题：构造path>=i+1的部分
        
        记录'('的个数，便于判断是否可以添加')'
        选或不选的思路
        选'(': dfs(i, open)->dfs(i + 1, open + 1)
        选')': dfs(i, open)->dfs(i + 1, open)
        
        时间复杂度：O(n*C(2n,n)) Catakan数
        空间复杂度：O(n)*/


        vector<string> ans;
        string path(2 * n, ' ');
        function<void(int, int)> dfs = [&] (int i, int open) { //i为path的当前长度
            if (i == 2 * n) {
                ans.push_back(path);
                return ;
            }
            if (open < n) {
                path[i] = '(';
                dfs(i + 1, open + 1);
            }
            if (i - open < open) {
                path[i] = ')';
                dfs(i + 1, open);  
            }
        };
        dfs(0, 0);
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

