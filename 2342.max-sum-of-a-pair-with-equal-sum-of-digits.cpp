/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 * @lcpr version=30109
 *
 * [2342] 数位和相等数对的最大和
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
    int count(int num) {
        int ans = 0;
        while (num) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, vector<int>> m;
        for (auto& x : nums) {
            m[count(x)].push_back(x);
        }
        for (auto it = m.begin(); it != m.end(); it ++) {
            vector<int> a = it->second;
            if (a.size() < 2) continue;
            
            sort(a.begin(), a.end());
            int n = a.size();
            ans = max(ans, a[n - 1] + a[n - 2]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [18,43,36,13,7]\n
// @lcpr case=end

// @lcpr case=start
// [10,12,19,14]\n
// @lcpr case=end

 */

