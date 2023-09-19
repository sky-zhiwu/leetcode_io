/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 * @lcpr version=21913
 *
 * [1351] 统计有序矩阵中的负数
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
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        int l = 0, r = grid[0].size() - 1;
        for (int i = 0; i < grid.size(); i ++) {
            
            if (grid[i][r] >= 0) continue;
            else {
                while (l < r) {
                    int mid = l + r >> 1;
                    if (grid[i][mid] >= 0) l = mid + 1;
                    else r = mid;
                }
                sum += grid[i].size() - l; 
            }
            l = 0;
            // cout << sum << "\n";
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[1,0]]\n
// @lcpr case=end

 */

