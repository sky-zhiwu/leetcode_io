/*
 * @lc app=leetcode.cn id=274 lang=cpp
 * @lcpr version=30103
 *
 * [274] H 指数
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
    int hIndex(vector<int>& citations) {
        // sort(citations.rbegin(), citations.rend());
        // int n = citations.size(), ans = 0;
        // for (int i = 0; i < n; i ++) {
        //     if (i + 1 <= citations[i]) 
        //         ans ++;
        //     else break;
        // }
        // return ans;

        int n = citations.size();
        vector<int> cnt(n + 1, 0);
        for (auto c : citations) {
            cnt[min(c, n)] ++;
        }
        int s = 0;// s为被引次数
        for (int i = n; i > 0; i --) {
            s += cnt[i];
            if (s >= i) return i;
        }
        return 0;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,6,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

 */

