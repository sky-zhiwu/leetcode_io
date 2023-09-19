// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=21913
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        // 时间复杂度O(n) 空间复杂度O(128) | O(1)-->s里的去重长度 
        unordered_map<char, int> h;
        int cnt = 0, l = 0, n = s.size();
        for (int r = 0; r < n; r ++) {
            h[s[r]] ++;
            
            while (h[s[r]] > 1) {
                h[s[l]] --;
                l ++;
            }
            cnt = max(cnt, r - l + 1);
        }
        return cnt;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

