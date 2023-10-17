/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 * @lcpr version=21917
 *
 * [1488] 避免洪水泛滥
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
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> sun;
        unordered_map<int, int> water;
        int n = rains.size();
        vector<int> res(n, 1);

        for (int i = 0; i < n; i ++) {
            int r = rains[i];

            if (r == 0) {
                sun.insert(i);
                continue;
            }
            
            if (water.count(r) != 0) { //需要抽水
                auto it = sun.lower_bound(water[r]);
                if (it == sun.end()) return {};
                res[*it] = r;
                sun.erase(it);
            }
            water[r] = i;
            res[i] = -1;

        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,0,0,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,1,2]\n
// @lcpr case=end

 */

