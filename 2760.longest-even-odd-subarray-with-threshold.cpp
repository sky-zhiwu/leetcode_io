/*
 * @lc app=leetcode.cn id=2760 lang=cpp
 * @lcpr version=30109
 *
 * [2760] 最长奇偶子数组
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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int cnt = 1;
                while (i+1 < n && nums[i+1] % 2 != nums[i] % 2 && nums[i+1] <= threshold) {
                    i ++;
                    cnt ++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,5,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5]\n4\n
// @lcpr case=end

 */

