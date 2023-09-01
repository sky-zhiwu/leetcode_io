/*
 * @lc app=leetcode.cn id=2811 lang=cpp
 * @lcpr version=21913
 *
 * [2811] 判断是否能拆分数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) return true;
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i] + nums[i + 1] >= m) return true;
        }
        return false;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2, 2, 1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, 3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2, 3, 3, 2, 3]\n6\n
// @lcpr case=end

 */

