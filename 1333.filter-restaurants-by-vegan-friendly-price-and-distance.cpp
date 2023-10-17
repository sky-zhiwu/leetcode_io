/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 * @lcpr version=21917
 *
 * [1333] 餐厅过滤器
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
    
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        vector<vector<int>> filter;
        vector<int> res;
        function<bool(vector<int>, vector<int>)> cmp = [&] (vector<int> a, vector<int> b) {
            return (a[1] == b[1]) ? a[0] > b[0] : a[1] > b[1];
        };
        sort(restaurants.begin(), restaurants.end(), cmp);

        function<bool(vector<int>, int, int, int)> check = [&](vector<int> a, int v, int mp, int md) {
            if ((v == 1 && a[2] == 1) || !v) {
                if (a[3] <= mp && a[4] <= md) return true;
            }  
            return false;
        };

        for (auto &r : restaurants) {
            if (check(r, veganFriendly, maxPrice, maxDistance)) {
                // filter.push_back({r[0], r[1]});
                res.push_back(r[0]);
            }
        }
        // sort(filter.begin(), filter.end(), cmp);
        // for (auto& f : filter) {
        //     res.push_back(f[0]);
        // }
        return res;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n1\n50\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n50\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n30\n3\n
// @lcpr case=end

 */

