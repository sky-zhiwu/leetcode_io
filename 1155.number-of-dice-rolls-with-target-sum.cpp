/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 * @lcpr version=30102
 *
 * [1155] 掷骰子等于目标和的方法数
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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        if (target > n * k || target < n) return 0;
        if (n == 1) {
            if(1 <= target && target <= k) return 1;
            else return 0;
        }
        int res = 0;
        for (int i = 0; i < k; i ++) {
            res = (res + numRollsToTarget(n - 1, k, target - i - 1) % MOD) % MOD; 
            // cout << res << "\n";
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// 6\n6\n7\n
// @lcpr case=end

// @lcpr case=start
//30\n30\n500\n
// @lcpr case=end

 */

