/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 * @lcpr version=30102
 *
 * [1962] 移除石子使总数最小
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
    int minStoneSum(vector<int>& piles, int k) {
        make_heap(piles.begin(), piles.end());
        while (k -- && piles[0] != 1) {
            pop_heap(piles.begin(), piles.end());
            piles.back() = piles.back() - (int)(piles.back() / 2) ;
            push_heap(piles.begin(), piles.end());
        }
        return accumulate(piles.begin(), piles.end(), 0);

    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,3,6,7]\n3\n
// @lcpr case=end

 */

