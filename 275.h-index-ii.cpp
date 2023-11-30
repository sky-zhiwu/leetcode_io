/*
 * @lc app=leetcode.cn id=275 lang=cpp
 * @lcpr version=30103
 *
 * [275] H 指数 II
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
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (n - mid <= citations[mid]) r = mid; //n-mid为篇数，c[mid]为次数
            else l = mid+1;
        }
        return (citations[r] == 0) ? 0 : n-r;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,100]\n
// @lcpr case=end

 */

