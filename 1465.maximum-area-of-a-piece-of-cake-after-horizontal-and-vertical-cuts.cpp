/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 * @lcpr version=30102
 *
 * [1465] 切割后面积最大的蛋糕
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
    typedef long long LL;
    const int MOD = 1'000'000'007;
    int max_size(int n, vector<int> cuts) {
        sort(cuts.begin(), cuts.end());
        int res = max(cuts[0], n - cuts.back());
        for (int i = 1; i < cuts.size(); i ++)
            res = max(res, cuts[i] - cuts[i - 1]);
        return res;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int row = max_size(h, horizontalCuts);
        int column = max_size(w, verticalCuts);
        return (LL) row * column % MOD;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1000000000\n1000000000\n[2]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 5\n4\n[1,2,4]\n[1,3]\n
// @lcpr case=end

// @lcpr case=start
// 5\n4\n[3,1]\n[1]\n
// @lcpr case=end

// @lcpr case=start
// 5\n4\n[3]\n[3]\n
// @lcpr case=end

 */

