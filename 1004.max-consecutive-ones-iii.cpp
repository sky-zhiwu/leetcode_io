/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=21913
 *
 * [1004] 最大连续1的个数 III
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
    int longestOnes(vector<int>& nums, int k) {
        // 改变的0肯定是连续的
        // if (count(nums.begin(), nums.end(), 0) <= k) return nums.size();
        
        // int cnt1 = 0;
        // int cnt = 0, n = nums.size(), l = 0;
        // queue<int> q;
        // //枚举右端点
        // for (int r = 0; r < n; r ++) {
        //     if (nums[r] == 1) {
        //         cnt ++;
        //     }else {
        //         q.push(r);
        //         if (q.size() <= k) {
        //             cnt ++;
        //         } else {
        //             int x = q.front();
        //             q.pop();
                    
        //             cnt = r - x;
        //         }
        //     }
            
        //     cnt1 = max(cnt1, cnt);
        // }
        // return cnt1;
        int res = 0, cnt = 0, l = 0, n = nums.size();
        for (int r = 0; r < n; r ++) {
            cnt += 1 - nums[r];
            while (cnt > k) {
                cnt -= (1 - nums[l]);
                l ++;
            }
            res = max(res, r - l + 1);
        }
        return res;



    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */

