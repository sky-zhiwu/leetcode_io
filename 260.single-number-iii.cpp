/*
 * @lc app=leetcode.cn id=260 lang=cpp
 * @lcpr version=30102
 *
 * [260] 只出现一次的数字 III
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
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) return nums;

        sort(nums.begin(), nums.end());

        int ans1 = nums[0], ans2 =nums[0];
        bool f1 = false, f2 = false;
        if (nums[0] != nums[1]) f1 = true;
        for (int i = 1; i < n - 1; i ++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                if (f1) {
                    ans2 = nums[i];
                    f2 = true;
                    return {ans1, ans2};
                }
                else {
                    ans1 = nums[i];
                    f1 = true;
                }
            }
        }
        if (!f2) ans2 = nums[n - 1];
        return {ans1, ans2};

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */

