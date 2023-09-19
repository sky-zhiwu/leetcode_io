/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=21913
 *
 * [4] 寻找两个正序数组的中位数
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
    vector<int> ins(vector<int>& nums1, vector<int>& nums2) { //把2插到1里面
        int l = 0, r = nums1.size() - 1;

        for (auto n2 : nums2) {
            if (n2 >= nums1[r]) {
                nums1.push_back(n2);
                continue;
            }
            while (l < r) {
                int mid = l + r >> 1; 
                if (n2 < nums1[mid]) r = mid;
                else l = mid + 1;
            }
            nums1.insert(nums1.begin() + l, n2);
            l ++, r = nums1.size() - 1;
        }
        return nums1;

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // for (auto n2 : nums2) nums1.push_back(n2);
        if (nums1.size() >= nums2.size()) nums1 = ins(nums1, nums2);
        else nums1 = ins(nums2, nums1);
        // sort(nums1.begin(), nums1.end());

        int mid1 = nums1.size() / 2, mid2 = (nums1.size() - 1) / 2;
        // cout << mid1 << " " << mid2 << " \n";
        return ((nums1[mid1] + nums1[mid2]) * 1.0 / 2);


    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

