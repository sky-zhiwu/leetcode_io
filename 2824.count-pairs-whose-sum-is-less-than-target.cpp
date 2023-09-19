/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 * @lcpr version=21913
 *
 * [2824] 统计和小于目标的下标对数目
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
    int countPairs(vector<int>& nums, int target) {
        // vector<pair<int, int>> pnum;
        // int sum = 0;
        // for (int i = 0; i < nums.size(); i ++) {
        //     pnum.push_back({nums[i], i});
        // } 
        // sort(pnum.begin(), pnum.end());
        // int l = 0, r = pnum.size() - 1;
        // while (l < r) {
        //     if (pnum[l].first + pnum[r].first < target) {
        //         sum += r - l;
        //         l ++;
                
        //     }
        //     else r --;
        // }
        // return sum;
        int sum = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        if (nums[n - 1] + nums[n - 2] < target) return (n - 1) * n / 2;
        if (nums[0] + nums[1] > target) return 0;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                sum += r - l; 
                l ++;
            }
            else r --;
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,1,2,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-6,2,5,-2,-7,-1,3]\n-2\n
// @lcpr case=end

 */

