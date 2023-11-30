/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30109
 *
 * [1] 两数之和
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
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> a;
        int n = nums.size();
        for (int i = 0; i < n; i ++) a.emplace_back(nums[i], i);
        sort(a.begin(), a.end());

        function<int(int, int, int)> erfen = [&] (int l, int r, int cha) -> int {
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                if (a[mid].first >= cha) r = mid;
                else if (a[mid].first < cha) l = mid;
            }
            return (r < n && a[r].first == cha) ? a[r].second : -1;
        };

        for (int i = 0; i < n; i ++) {
            int cha = target - a[i].first;
            int idx = a[i].second;

            if (cha > a[i].first) {
                int res = erfen(i, n, cha);
                if (res != -1) return {res, idx};
            }
            else if (cha == a[i].first){
                if (i - 1 >= 0 && nums[a[i - 1].second] == cha) return {a[i - 1].second, idx};
                if (i + 1 < n && nums[a[i + 1].second] == cha) return {a[i + 1].second, idx};
            }
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

