/*
 * @lc app=leetcode.cn id=137 lang=cpp
 * @lcpr version=21917
 *
 * [137] 只出现一次的数字 II
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
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1]) return nums[0];

        for (int i = 1; i < n - 1; i ++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
        }
        return nums[n - 1];

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1,0,1,99]\n
// @lcpr case=end

 */

