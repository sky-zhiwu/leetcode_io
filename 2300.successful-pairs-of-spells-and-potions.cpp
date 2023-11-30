/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 * @lcpr version=30106
 *
 * [2300] 咒语和药水的成功对数
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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs(spells.size(), 0);
        int n = potions.size(), idx = 0;
        sort(potions.begin(), potions.end());
        function<int(double)> erfen = [&] (double goal) -> int {
            // 找到portions里第一个大于goal的数
            int l = 0, r = n - 1;
            if (potions[r] < goal) return n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (potions[mid] >= goal) r = mid;
                else l = mid + 1;
            }
            return l;
        };
        for (auto& s : spells) {
            double goal = success * 1.0 / s;
            pairs[idx] = n - erfen(goal);
            idx ++;
        } 
        return pairs;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */

