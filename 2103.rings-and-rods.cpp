/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 * @lcpr version=30104
 *
 * [2103] 环和杆
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
    int countPoints(string rings) {
        int n = rings.size();
        vector<vector<int>> r(10, vector<int>(3));
        for (int i = 0; i <= rings.size() - 2; i += 2) {
            int x1, x2;
            if (rings[i] == 'B') x1 = 0;
            else if (rings[i] == 'R') x1 = 1;
            else x1 = 2;
            x2 = rings[i  + 1] - '0';
            r[x2][x1] = 1;
        }
        int ans = 0;
        for (int i = 0; i < 10; i ++) {
            ans += (r[i][0] == 1 &&r[i][1] == 1 &&r[i][2] == 1) ? 1 : 0;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "B0B6G0R6R0R6G9"\n
// @lcpr case=end

// @lcpr case=start
// "B0R0G0R9R0B0G0"\n
// @lcpr case=end

// @lcpr case=start
// "G4"\n
// @lcpr case=end

 */

