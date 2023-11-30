/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 * @lcpr version=30102
 *
 * [2208] 将数组和减半的最少操作次数
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
    int halveArray(vector<int>& nums) {
        // vector<double> doubleVec(nums.begin(), nums.end());
        vector<double> doubleVec(nums.size());
        int ans = 0;
        transform(nums.begin(), nums.end(), doubleVec.begin(), [](int x) { return (double)x;});
        long long initial_sum = accumulate(nums.begin(), nums.end(), 0LL);
        double target_num = initial_sum / 2.0;
        make_heap(doubleVec.begin(), doubleVec.end());
        while (initial_sum > target_num) {
            pop_heap(doubleVec.begin(), doubleVec.end());
            doubleVec.back() /= 2.0;
            initial_sum -= doubleVec.back();
            push_heap(doubleVec.begin(), doubleVec.end());
            cout << doubleVec.back()  << " " << initial_sum << " " << target_num << "\n";
            ans ++;
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,19,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [18,22,62,61,1,88,17,98,38,32,51,57,7,29,40,61,62,13,89,41,73,85,88,60,59,76,71,76,76,41,29,43,19,9,79]\n
// @lcpr case=end

 */

