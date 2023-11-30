/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 * @lcpr version=30106
 *
 * [1248] 统计「优美子数组」
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> m;
        for (int i = 0; i < n; i ++) {
            if (nums[i] % 2 != 0) m.push_back(i);
        }
        int ans = 0, ms = m.size();
        if (ms < k) return 0;
        for (int i = 0; i + k <= ms; i ++) {
            int l = 0, r = 0;
            if (i == 0) l = m[i] + 1;
            else l = m[i] - m[i - 1];
            if (i + k == ms) r = n - m[ms - 1];
            else r = m[i + k] - m[i + k - 1];
            ans += l * r;
            // cout << l << " " << r << " " << ans << "\n";
        }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,1,2,2,1,2,2,2]\n2\n
// @lcpr case=end

 */

