/*
 * @lc app=leetcode.cn id=611 lang=cpp
 * @lcpr version=21913
 *
 * [611] 有效三角形的个数
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

    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        // reverse(nums.begin(), nums.end());
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n - 2; i ++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[i] >= nums[l] + nums[r]) r --;
                else {
                    sum += r - l;
                    l ++;
                }
            }

        }
        return sum;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,4]\n
// @lcpr case=end

 */

