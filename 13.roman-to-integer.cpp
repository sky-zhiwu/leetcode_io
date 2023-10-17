/*
 * @lc app=leetcode.cn id=13 lang=cpp
 * @lcpr version=21917
 *
 * [13] 罗马数字转整数
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
    int romanToInt(string s) {
        int i = 0, res = 0, n = s.size();
        while (i < n) {
            if (s[i] == 'I') {
                if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    res += (s[i + 1] == 'V') ? 4 : 9;
                    
                    i ++;
                }else res += 1;
            }
            else if (s[i] == 'X') {
                if (i + 1 < n && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    res += (s[i + 1] == 'L') ? 40 : 90;
                    i ++;
                }else res += 10;
            }
            else if (s[i] == 'C') {
                if (i + 1 < n && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    res += (s[i + 1] == 'D') ? 400 : 900;
                    i ++;
                }else res += 100;
            }
            else if (s[i] == 'V') res += 5;
            else if (s[i] == 'L') res += 50;
            else if (s[i] == 'D') res += 500;
            else res += 1000;
            i ++;
            // cout << "i: " << i << "\n";
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "IV"\n
// @lcpr case=end

// @lcpr case=start
// "IX"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */

