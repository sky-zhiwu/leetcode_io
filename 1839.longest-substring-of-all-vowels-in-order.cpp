/*
 * @lc app=leetcode.cn id=1839 lang=cpp
 * @lcpr version=30105
 *
 * [1839] 所有元音按顺序排布的最长子字符串
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
    int longestBeautifulSubstring(string word) {
        // 滑动窗口
        int n = word.size(), ans = 0;
        int i = 0, j = 0, cnt = 0;
        while (j < n-1) {
            while (j + 1 < n && word[j] <= word[j + 1]) {
                if (word[j] < word[j + 1]) cnt ++;
                j++;
            }
            if (cnt == 4) ans = max(ans, j - i + 1);
            cnt = 0;
            i = ++j;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aeiaaioaaaaeiiiiouuuooaauuaeiu"\n
// @lcpr case=end

// @lcpr case=start
// "aeeeiiiioooauuuaeiou"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

