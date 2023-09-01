/*
 * @lc app=leetcode.cn id=888 lang=cpp
 * @lcpr version=21913
 *
 * [888] 公平的糖果交换
 */
using namespace std;
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        // int s1 = 0, s2 = 0, sum = 0;
        // vector<int> res;
        // for (auto alice : aliceSizes) s1 += alice;
        // for (auto bob : bobSizes) s2 += bob;
        // sum = s1 + s2;

        // unordered_set<int> ans(aliceSizes.begin(), aliceSizes.end());
        // for (auto&& bob : bobSizes) {
        //     int a = bob + s1 - sum / 2;
        //     if (ans.count(a)) {
        //         res = vector<int>{a, bob};
        //         break;
        //     }
        // }
        // return res;

        //二分
        int s1 = 0, s2 = 0, sub = 0;
        vector<int> res;
        for (auto alice : aliceSizes) s1 += alice;
        for (auto bob : bobSizes) s2 += bob;
        sub = (s1 - s2) / 2;
        // cout << s1 << ' ' << s2 << ' ' << sub << '\n';
        sort(bobSizes.begin(), bobSizes.end());

        //a - b = (s1 - s2) / 2;
        for (auto a : aliceSizes) {
            int l = 0, r = bobSizes.size() - 1;
            while (l <= r && l >= 0 && r < bobSizes.size()) {
                int mid = l + r >> 1;
                // cout << mid << ' ';
                if (bobSizes[mid] + sub == a) { 
                    
                    return vector<int>{a, bobSizes[mid]}; }
                if (bobSizes[mid] + sub > a) r = mid - 1;
            else l = mid + 1;
            }
            
        }

        return res;
        
        
        
        

    }

};
// @lc code=end



/*
// @lcpr case=start
// [35,17,4,24,10]\n[63,21]\n
// @lcpr case=end

// @lcpr case=start
// [79,97,89,31,66]\n[66,23,76,91,60]\n
// @lcpr case=end

// @lcpr case=start
// [2]\n[1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5]\n[2,4]\n
// @lcpr case=end

 */

