/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 * @lcpr version=21913
 *
 * [2596] 检查骑士巡视方案
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

    bool check(int x1, int y1, int x2, int y2) {
        // if ((abs(x1 - x2) == 1 && abs(y2 - y1) == 2) || (abs(x1 - x2) == 2 && abs(y2 - y1) == 1))
        if (abs(x1 - x2) * abs(y1 - y2) == 2)
            return true;
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        vector<pair<int, vector<int>>> q;
        int n = grid.size(), i = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                q.push_back({grid[i][j], {i, j}});
            }
        }
        sort(q.begin(), q.end());
        while (i < q.size() - 1) {
            if (check(q[i].second[0], q[i].second[1], q[i + 1].second[0], q[i + 1].second[1])) {
                i ++;
            }
            else break; 
        }
        if (i == q.size() - 1) return true;
        else return false;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,3,6],[5,8,1],[2,7,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[24,11,22,17,4],[21,16,5,12,9],[6,23,10,3,18],[15,20,1,8,13],[0,7,14,19,2]]\n
// @lcpr case=end

 */

