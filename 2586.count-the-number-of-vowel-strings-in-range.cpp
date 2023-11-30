/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 * @lcpr version=30105
 *
 * [2586] 统计范围内的元音字符串数
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
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> s = {'a','e','i','o','u'};
        int n = words.size(), ans = 0;
        for (int i = left; i <= right; i ++) {
            char begin = *(words[i].begin()), end = *(words[i].end() - 1);
            if (s.find(begin) != s.end() && s.find(end) != s.end()) ans ++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["are","amy","u"]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// ["hey","aeo","mu","ooo","artro"]\n1\n4\n
// @lcpr case=end

 */

