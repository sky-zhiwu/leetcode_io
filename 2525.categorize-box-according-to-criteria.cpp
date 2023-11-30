/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 * @lcpr version=30102
 *
 * [2525] 根据规则将箱子分类
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
    string categorizeBox(int length, int width, int height, int mass) {
        long long v = (long long)length *  (long long)width *  (long long)height;
        bool bu = false, he = false;
        if (length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9) bu = true;
        if (mass >= 100) he = true;
        if (bu && he) return "Both";
        if (!bu && !he) return "Neither";
        return bu ? "Bulky" : "Heavy";

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1000\n35\n700\n300\n
// @lcpr case=end

// @lcpr case=start
// 299\n3968\n3272\n727\n
// @lcpr case=end

 */

