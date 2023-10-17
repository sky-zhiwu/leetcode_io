/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21917
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        // 暴力
        /*function<bool(int, int)> check = [&](int start, int end) {
            for (int i = start, j = end; i < j; i ++, j --) {
                if (s[i] != s[j]) return false;
            } 
            return true;
        };
        string res = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i ++) {
            for (int j = s.size() - 1; j >= i; j --) {
                if (s[i] == s[j]) {
                    if (check(i, j)) {
                        
                        cnt = max(cnt, j - i + 1);
                        
                        if (cnt > res.size()) res = s.substr(i, j - i + 1);
                        break;
                    }
                } 
            }
        }
        return res;*/

        // 动态规划
        int n = s.size();
        if (n < 2) return s;

        int maxlen = 1, start = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i ++) dp[i][i] = true; // 所有长度为 1 的子串都是回文串

        for (int len = 2; len <= n; len ++) {
            //len 为子串长度
            for (int i = 0; i < n; i ++) { //len = j - i + 1, i为左边界
                int j = len + i - 1;
                if (j >= n) break;

                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j - i < 3) dp[i][j] = true; // ij之间相隔最多一个字母
                    else dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

