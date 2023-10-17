/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=21917
 *
 * [17] 电话号码的字母组合
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
    vector<string> letterCombinations(string digits) {
        vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        // 原问题 -> 子问题
        /*回溯三问
        1.当前操作？枚举path[i]填入的字母
        2.子问题？ 构造字符串>=i的部分
        3.下一个子问题？ 构造字符串>=i + 1的部分 dfs(i)->dfs(i + 1)*/

        // 时间复杂度O(n*4^n) 空间复杂度O(n)
        int n = digits.size();
        if (n == 0) return {};
        string path(n, ' ');
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.push_back(path);
                return;
            }
            for (char c : s[digits[i] - '0']) {
                path[i] = c;
                dfs(i + 1);
            }
        };
        dfs(0);
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

