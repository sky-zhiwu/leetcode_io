/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 * @lcpr version=21913
 *
 * [1337] 矩阵中战斗力最弱的 K 行
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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ans;
        vector<int> res;
        for (int i = 0; i < mat.size(); i ++) {
            int l = 0, r = mat[i].size() - 1;
            if (mat[i][r] == 1) { //最右边是1说明都是军人
                ans.push_back({r + 1, i});
                continue;
            }
            else if (mat[i][l] == 0) { //最左边是0说明都是平民
                ans.push_back({0, i});
                continue;
            }
            while (l < r) {
                int mid = l + r >> 1;
                if (mat[i][mid] == 1) l = mid + 1;
                else r = mid;
            }
            // cout << "\n" << l << " " << i << "\n";
            ans.push_back({l, i});
        }
        sort(ans.begin(), ans.end());
        ans.resize(k);
        for (auto a : ans) {
            res.push_back(a.second);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,0],[1,1,1,1,1]]\n3\n
// @lcpr case=end

 */

