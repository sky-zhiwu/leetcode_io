/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 * @lcpr version=21914
 *
 * [2591] 将钱分给最多的儿童
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
    int distMoney(int money, int children) {
        if (money < children) return -1; // 下限，分不够
        if (money > children * 8) return children - 1; //上限
        if (money == 8 * children - 4) return children - 2;
        // 向下取整  money - 8n >= children - n --> 7n <= money - children;
        return (money - children) / 7; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n
// @lcpr case=end

 */

