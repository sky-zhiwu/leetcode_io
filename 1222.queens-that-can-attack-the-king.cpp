/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 * @lcpr version=21913
 *
 * [1222] 可以攻击国王的皇后
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
    const int direction[8][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1} };// 右 左 上 下 左上 左下 右上 右下
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 向八个方向映射
        vector<vector<int>> res;
        bool isqueen[8][8] = {false};
        for (auto& q : queens) {
            isqueen[q[0]][q[1]] = true;
        }
            

        for (auto& d : direction) {
            int x = king[0] + d[0], y = king[1] + d[1];
            while (0 <= x && x < 8 && 0 <= y && y < 8) {
                if (isqueen[x][y]) {
                    res.push_back({x, y});
                    break;
                }
                x += d[0], y += d[1];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[0,7],[5,1],[2,5],[7,2],[1,2],[6,7],[3,3],[5,5],[1,5],[5,0],[0,4],[4,1],[1,1],[3,2],[2,3],[4,2],[1,0],[6,5],[2,7],[3,1],[4,3],[3,4]]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]]\n[3,3]\n
// @lcpr case=end

// @lcpr case=start
// [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]]\n[3,4]\n
// @lcpr case=end

 */

