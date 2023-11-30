/*
 * @lc app=leetcode.cn id=318 lang=cpp
 * @lcpr version=30104
 *
 * [318] 最大单词长度乘积
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
    int maxProduct(vector<string>& words) {
        // int n = words.size(), idx = 0;
        // vector<int> m(n); // 最高是2^26
        // for (auto& w : words) {
        //     int t = 0;
        //     for (auto& c : w) {
        //         t |= (1 << (c-'a'));
        //     }
        //     m[idx++] = t;
        // }
        // int ans = 0;
        // for (int i = 0; i < n; i ++) {
        //     for(int j = i + 1; j < n; j ++) {
        //         if ((m[i] & m[j]) == 0) {//word之间无交集 
        //             int x = words[i].size() * words[j].size();
        //             ans = max(ans, x);
        //         }
        //     }
        // }
        // return ans;

        // 优化
        int n = words.size(), idx = 0;
        unordered_map<int, int> m; // 最高是2^26
        for (auto& w : words) {
            int t = 0, len = w.size();
            for (auto& c : w) {
                t |= (1 << (c-'a'));
            }
            if (m.find(t) == m.end() || (m[t]< len)) { 
                m[t] = len; //已经有过相同词的字符串了并且小于当前的长度,则选择当前字符串    
            }
        }
        int ans = 0;
        for (auto& i1 : m) {
            for (auto& i2 : m) {
                if ((i1.first & i2.first) == 0) ans = max(ans, i1.second * i2.second);
            }
        }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcw","baz","foo","bar","xtfn","abcdef"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","ab","abc","d","cd","bcd","abcd"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","aa","aaa","aaaa"]\n
// @lcpr case=end

 */

