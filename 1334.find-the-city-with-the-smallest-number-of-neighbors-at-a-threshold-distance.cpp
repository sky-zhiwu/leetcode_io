/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 * @lcpr version=30109
 *
 * [1334] 阈值距离内邻居最少的城市
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> w(n, vector<int>(n, INT_MAX / 2));
        for (auto& e : edges) { //构造矩阵
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt;
        }
        // vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n)));
        // // dfs(k,i,j)为i到j的最短路长度，且经过的节点编号都小于等于k
        // function<int(int, int, int)> dfs = [&] (int k, int i, int j) -> int {
        //     if (k < 0) return w[i][j];
        //     auto& res = memo[k][i][j];
        //     if (res) return res;
        //     return res = min(dfs(k - 1, i, j), dfs(k - 1, i, k) + dfs(k - 1, k, j));
        // };

        // vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(n, vector<int>(n)));
        // f[0] = w;
        // for (int k = 0; k < n; k ++) {
        //     for (int i = 0; i < n; i ++) {
        //         for (int j = 0; j < n; j ++) {
        //             f[k + 1][i][j] = min(f[k][i][j], f[k][i][k] + f[k][k][j]);
        //         }
        //     }
        // }

        auto f = move(w);
        for (int k = 0; k < n; k ++) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        int ans = 0;
        int min_cnt = n;
        for (int i = 0; i < n; i ++) {
            int cnt = 0;
            for (int j = 0; j < n; j ++) {
                if (j != i && f[i][j] <= distanceThreshold) cnt ++;
            }
            if (cnt <= min_cnt) {
                min_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]\n2\n
// @lcpr case=end

 */

