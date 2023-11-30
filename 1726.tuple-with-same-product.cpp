/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 * @lcpr version=30102
 *
 * [1726] 同积元组
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
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;
        int ans = 0;
        // 时间复杂度o(n^2)
        unordered_map<int, int> map;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int val = nums[i] * nums[j];
                auto it = map.find(val);
                if (it != map.end()) ans += 8 * map[val];
                map[val] ++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,5,10]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,6,8,12]\n
// @lcpr case=end

 */

