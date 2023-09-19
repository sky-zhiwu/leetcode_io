/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=21913
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        // 相向双指针
        // 时间复杂度 O(n)
        // 空间复杂度 O(1)
        int sum = 0, n = height.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int s = (r - l) * min(height[l], height[r]);
            sum = max(sum, s);
            //如果左边矮，去掉左边
            if (height[l] < height[r]) l ++;
            else r --;
        }
        return sum;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

