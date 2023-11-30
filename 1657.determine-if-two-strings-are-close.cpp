/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 * @lcpr version=30111
 *
 * [1657] 确定两个字符串是否接近
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
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 != n2) return false;
        vector<int> a1(26, 0), a2(26, 0);
        for (auto x : word1) a1[x - 'a'] ++;
        for (auto x : word2) a2[x - 'a'] ++;
        for (int i = 0; i < 26; i ++) 
            if (a1[i] == 0 && a2[i] != 0 || a2[i] == 0 && a1[i] != 0)
                return false;
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        for (int i = 0; i < 26; i ++)
            if (a1[i] != a2[i]) return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

// @lcpr case=start
// "cabbba"\n"abbccc"\n
// @lcpr case=end

// @lcpr case=start
// "cabbba"\n"aabbss"\n
// @lcpr case=end

 */

