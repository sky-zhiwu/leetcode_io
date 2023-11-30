/*
 * @lc app=leetcode.cn id=2736 lang=cpp
 * @lcpr version=30109
 *
 * [2736] 最大和查询
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
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> a(nums1.size());
        for (int i = 0; i < nums1.size(); i ++) 
            a[i] = {nums1[i], nums2[i]};
        sort(a.begin(), a.end(), [](auto& a, auto& b) {return a.first > b.first;}); //降序排列

        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int i, int j) {return queries[i][0] > queries[j][0];});

        vector<int> ans(queries.size());
        vector<pair<int, int>> st; // 单调栈
        int j = 0;
        for (int i : qid) {
            int x = queries[i][0], y = queries[i][1];
            for (; j < a.size() && a[j].first >= x; j ++) {
                while (!st.empty() && st.back().second <= a[j].first + a[j].second) {
                    st.pop_back();
                }
                if (st.empty() || st.back().first < a[j].second) {
                    st.emplace_back(a[j].second, a[j].first + a[j].second);
                }
            }
            auto it = lower_bound(st.begin(), st.end(), y, 
                [] (const auto& p, int val) {return p.first < val;});
            ans[i] = it != st.end() ? it->second : -1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,1,2]\n[2,4,9,5]\n[[4,1],[1,3],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,5]\n[2,3,4]\n[[4,4],[3,2],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n[2,3]\n[[3,3]]\n
// @lcpr case=end

 */

