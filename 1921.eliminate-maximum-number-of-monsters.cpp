/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 * @lcpr version=21913
 *
 * [1921] 消灭怪物的最大数量
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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrivalTimes(n);
        for (int i = 0; i < n; i++) {
            arrivalTimes[i] = (dist[i] - 1) / speed[i] + 1;
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());
        for (int i = 0; i < n; i++) {
            if (arrivalTimes[i] <= i) {
                return i;
            }
        }
        return n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4]\n[1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3]\n[1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n[5,3,2]\n
// @lcpr case=end

 */

