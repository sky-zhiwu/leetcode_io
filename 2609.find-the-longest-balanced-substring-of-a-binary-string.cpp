/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 * @lcpr version=30105
 *
 * [2609] 最长平衡子字符串
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
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; ) {
            int cnt0 = 0, cnt1 = 0;
            if (s[i] == '0') {
                while (i < n && s[i] == '0') {cnt0 ++; i ++;}
                while (i < n && s[i] == '1') {cnt1 ++; i ++;}
                ans = max(ans, min(cnt0, cnt1) * 2);
            }
            else i ++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "01000111"\n
// @lcpr case=end

// @lcpr case=start
// "00111"\n
// @lcpr case=end

// @lcpr case=start
// "111"\n
// @lcpr case=end

 */

