/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 * @lcpr version=21913
 *
 * [2605] 从两个数字数组里生成最小数字
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

    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, int> cnt;
        // for (int n1 : nums1) cnt[n1] ++;
        // for (int n2 : nums2) cnt[n2] ++;
        // int min_num = 10;

        // for (const auto& pair : cnt) {
        //     if (pair.second >= 2) {
        //         min_num = min(min_num, pair.first);
        //     }
        // }
        // if (min_num != 10) return min_num;
        
        // int min1 = *min_element(nums1.begin(), nums1.end());
        // int min2 = *min_element(nums2.begin(), nums2.end());
        
        // return (min(min1, min2) * 10 + max(min1, min2));
        
        //哈希表或数组 + 枚举
        bitset<10> s1;
        bitset<10> s2;
        for (int i : nums1) s1[i] = 1;
        for (int i : nums2) s2[i] = 1;

        int a = 0, b = 0;
        for (int i = 1; i < 10; i ++) {
            if (s1[i] && s2[i]) return i;
            if (!a && s1[i]) a = i;
            if (!b && s2[i]) b = i;
        }
        return min(a * 10 + b, b * 10 + a);
        

        
         

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,3]\n[5,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,2,6]\n[3,1,7]\n
// @lcpr case=end

 */

