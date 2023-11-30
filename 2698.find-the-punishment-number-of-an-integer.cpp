/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 * @lcpr version=30102
 *
 * [2698] 求一个整数的惩罚数
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
#include <numeric>
#include <unordered_set>
#include <cmath>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int punishmentNumber(int n) {
        /*131.分割回文串
          选或者不选的问题

          当前操作：选择s[i..j]，加入path
          子问题：从>=i的数字构造子集
          下一个子问题：从>=j+1的数字构造子集
          */ 
        vector<int> path;
        bool ans = false;
        function<void(string, int, int)> dfs = [&] (string s, int i, int t) {
            if (i == s.size()) {
                if (accumulate(path.begin(), path.end(), 0) == t) ans = true;
                return ;
            }
            for (int j = i; j < s.size(); j ++) {
                int sum = 0;
                for (int k = i; k <= j; k ++) sum = sum * 10 + (s[k] - '0');
                path.push_back(sum);
                dfs(s, j + 1, t);
                path.pop_back();
            }
        };
        function<bool(int)> search = [&] (int i) ->bool {
            string s = to_string(i * i);
            dfs(s, 0, i);
            return ans;
        };
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            int x = i * i; 
            // 找x里有没有子字符串对应的整数值之和等于i
            if (search(i)) sum += x;
            ans = false; //重置
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 37\n
// @lcpr case=end

 */

