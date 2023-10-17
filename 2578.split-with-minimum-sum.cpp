/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 * @lcpr version=21917
 *
 * [2578] 最小和分割
 */using namespace std;
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
#include <cmath>
// @lc code=start
class Solution {
public:
    int splitNum(int num) {
        int res = 0;
        vector<int> nums;
        while (num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            res += pow(10, i/2) * (nums[i] + ((i + 1 == n) ? 0 : nums[i + 1]));
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 4325\n
// @lcpr case=end

// @lcpr case=start
// 687\n
// @lcpr case=end

 */

