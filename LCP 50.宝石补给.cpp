/*
 * @lc app=leetcode.cn id=LCP 50 lang=cpp
 * @lcpr version=21913
 *
 * [LCP 50] 宝石补给
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
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        
        for (auto& o : operations) {
            int give = gem[o[0]] / 2;
            gem[o[0]] -= give;
            gem[o[1]] += give;
        }
        sort(gem.begin(), gem.end());
        
        return gem[gem.size() - 1] - gem[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2]\n[[0,2],[2,1],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [100,0,50,100]\n[[0,2],[0,1],[3,0],[3,0]]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0]\n[[1,2],[3,1],[1,2]]\n
// @lcpr case=end

 */

