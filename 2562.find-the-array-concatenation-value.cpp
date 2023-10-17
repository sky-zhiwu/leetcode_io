/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 * @lcpr version=21917
 *
 * [2562] 找出数组的串联值
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
#include<cmath>
// @lc code=start
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n / 2; i ++) {
            int l = nums[i], r = nums[n - i - 1];
            string str = to_string(r);
            sum += (long long)l * pow(10, str.size()) + r;
        }
        if (n % 2 == 1) sum += nums[n / 2];
        return sum;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,52,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,14,13,8,12]\n
// @lcpr case=end

 */

