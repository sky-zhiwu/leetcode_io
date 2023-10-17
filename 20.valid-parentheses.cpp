/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=21917
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') st.emplace(c);
            else {
                if (st.empty()) return false;
                char t = st.top();
                if ((t == '(' && c == ')') || (t == '{' && c == '}') || (t == '[' && c == ']')) {
                    st.pop();
                }else return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */

