/*
 * @lc app=leetcode.cn id=2678 lang=cpp
 * @lcpr version=30102
 *
 * [2678] 老人的数目
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
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto x : details) {
            int age = (x[11] - '0') * 10 + (x[12] - '0');
            if (age > 60) ans ++;
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["7868190130M7522","5303914400F9211","9273338290F4010"]\n
// @lcpr case=end

// @lcpr case=start
// ["1313579440F2036","2921522980M5644"]\n
// @lcpr case=end

 */

