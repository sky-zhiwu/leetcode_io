/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 * @lcpr version=21913
 *
 * [1170] 比较字符串最小字母出现频次
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
    int f(string s) {
        pair<int, int> ans = {s[0] - '0', 1};
        for (int i = 0; i < s.size() - 1; i ++) {
            if (s[i] - '0' == s[i + 1] - '0' && ans.first == s[i] - '0') {
                ans.second ++;
            }
            else if (s[i] - '0' > s[i + 1] - '0') {
                if (ans.first > s[i + 1] - '0') {
                    ans.first = s[i + 1] - '0';
                    ans.second = 1;
                }
                else if (ans.first == s[i + 1] - '0') {
                    ans.second ++;
                }
                
            } 
        }
        
        return ans.second;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsNum;
        vector<int> queNum;
        vector<int> res;
        for (int i = 0; i < words.size(); i ++) {
            wordsNum.push_back(f(words[i]));
        }
        // cout << "\n";
        // for (int i = 0; i < words.size(); i ++) {
        //     cout << wordsNum[i] << " ";
        // }
        // cout << "\n";
        sort(wordsNum.begin(), wordsNum.end());
        for (int i = 0; i < queries.size(); i ++) {
            queNum.push_back(f(queries[i]));
            // cout << " " << queNum[i] << " ";
            int l = 0, r = wordsNum.size() - 1;
            while (l < r) {
                int mid = l + r  >> 1;
                if (wordsNum[mid] > queNum[i]) r = mid ;
                else l = mid + 1;
            }
            if (wordsNum[l] <= queNum[i])  res.push_back(0);
            else res.push_back(wordsNum.size() - l);
        }
    return res;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cbd"]\n["zaaaz"]\n
// @lcpr case=end

// @lcpr case=start
// ["bbb","cc"]\n["a","aa","aaa","aaaa"]\n
// @lcpr case=end

// @lcpr case=start
// ["bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"]\n
["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]\n
// @lcpr case=end

// @lcpr case=start
// ["aabbabbb","abbbabaa","aabbbabaa","aabba","abb","a","ba","aa","ba","baabbbaaaa","babaa","bbbbabaa"]\n
["b","aaaba","aaaabba","aa","aabaabab","aabbaaabbb","ababb","bbb","aabbbabb","aab","bbaaababba","baaaaa"]\n
// @lcpr case=end

 */

