/*
 * @lc app=leetcode.cn id=930 lang=cpp
 * @lcpr version=30105
 *
 * [930] 和相同的二元子数组
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
#include <numeric>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 滑动窗口
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 && goal == 0) {
            return (1 + n) * n / 2;
        }
        if (sum < goal || sum == 0) return 0;
        sum = 0;

        int i = 0, j = 0, ans = 0;
        while (j < n) {
            sum += nums[j];
            // cout << sum << " ";
            if (sum < goal) {j++;}
            else if (sum > goal) {
                if (i < j) {sum -= nums[i]; i ++;}
                else if (i == j) {i++; j ++; sum = 0;}
            }
            else {
                int t = j + 1, p = i;
                while (t < n && nums[t] == 0) {t ++;}
                while (p < j && nums[p] == 0) {p ++;}
                ans += (t - j) * (p - i + 1);
                if (goal != 0) {
                    i = p;
                    sum -= nums[i]; i ++;
                    j = t;
                }
                else {
                    sum -= nums[i]; i ++;
                    j ++;
                }
            }
        }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0]\n3\n
// @lcpr case=end

 */

