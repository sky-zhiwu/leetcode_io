/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 * @lcpr version=21913
 *
 * [2516] 每种字符至少取 K 个
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
    int takeCharacters(string s, int k) {
        int cnt['d']{}, n = s.size(), res = n;
        for (char c : s) cnt[c]++;
        int l = 0;
        if (cnt['a'] < k || cnt['b'] < k || cnt['c'] < k) return -1;
        for (int r = 0; r < n; r ++) {
            cnt[s[r]] --;
            while ((cnt['a'] < k || cnt['b'] < k || cnt['c'] < k) && l <= r) {
                 
                cnt[s[l++]] ++;
            }
            res = min(res, n - r + l - 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabaaaacaabc"\n2\n
// @lcpr case=end

// @lcpr case=start
// "a"\n1\n
// @lcpr case=end

 */

