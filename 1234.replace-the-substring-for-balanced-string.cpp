/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 * @lcpr version=21913
 *
 * [1234] 替换子串得到平衡字符串
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
    int balancedString(string s) {
        int n = s.length(), m = n / 4, cnt['X']{};
        for (char c : s) cnt[c] ++;
        int res = n, l = 0;
        if (cnt['Q'] == m && cnt['R'] == m && cnt['E'] == m && cnt['W'] == m)
            return 0;
        for (int r = 0; r < n; r ++) {
            cnt[s[r]] --;
            while (cnt['Q'] <= m && cnt['R'] <= m && cnt['E'] <= m && cnt['W'] <= m) {
                res = min(res, r - l + 1);
                cnt[s[l++]] ++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "QWER"\n
// @lcpr case=end

// @lcpr case=start
// "WQWRQQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQQ"\n
// @lcpr case=end

 */

