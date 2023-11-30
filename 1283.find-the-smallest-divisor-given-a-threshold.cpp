/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 * @lcpr version=30105
 *
 * [1283] 使结果不超过阈值的最小除数
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
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int max_div = nums.back();
        int l = 1, r = max_div;
        function<int(int)> cal = [&] (int x) -> int{
            int res = 0;
            for (auto& num : nums) res += (num + x - 1) / x;
            return res;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (cal(mid) > threshold) l = mid + 1;
            else r = mid; 
        }
        return l;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,9]\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5,7,11]\n11\n
// @lcpr case=end

// @lcpr case=start
// [19]\n5\n
// @lcpr case=end

 */

