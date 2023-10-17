/*
 * @lc app=leetcode.cn id=2731 lang=cpp
 * @lcpr version=21917
 *
 * [2731] 移动机器人
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
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size() - 1;
        int MOD = 1e9 + 7;
        for (int i = 0; i <= n; i ++) {
            if (s[i] == 'R') nums[i] += d;
            else nums[i] -= d;
        }
        sort(nums.begin(), nums.end());
        long long sum = (n * (long long)((long long)nums[n] - (long long)nums[0])) % MOD;
        for (int i = 1; i < n; i ++)
            sum = (sum + (long long)(2 * i - n) * nums[i]) % MOD;

        return sum;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,0,2]\n"RLL"\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0]\n"RL"\n2\n
// @lcpr case=end

 */

