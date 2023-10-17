/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=21917
 *
 * [131] 分割回文串
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
    bool check(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l ++, r --;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        // 从答案分析
        /*回溯三问
        1.当前操作？枚举下标j >= i 的逗号，加入path
        2.子问题？ 从>=i的部分构造子集
        3.下一个子问题？ >=j + 1的数字中构造子集 dfs(i)->dfs(i + 1/2/3/.../n)*/

        vector<vector<string>> res;
        vector<string> path;
        int n = s.size();
        function<void(int)> dfs = [&] (int i) {

            if (i == n) { // 可省略
                res.push_back(path);
                return ;
            }
            for (int j = i; j < n; j ++) { //j是子串的结束部分
                string t;
                for (int m = i; m <= j; m ++) {
                    t.push_back(s[m]);
                }
                if (check(t)) {
                    path.push_back(t);
                    dfs(j + 1);
                    path.erase(path.end() - 1);
                }
            }
        };
        dfs(0);
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

