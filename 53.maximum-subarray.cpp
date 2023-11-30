/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30109
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int>& nums) {
        // 前缀和
        int n = nums.size(), ans = INT_MIN;
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int i = 1; i < n + 1; i ++) {
            int a = s[i];
            for (int j = i + 1; j < n + 1; j ++) {
                a = max(a, s[j] - s[i]);
            }
            ans = max(ans, a);
        }
        return ans;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

