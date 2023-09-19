/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 * @lcpr version=21913
 *
 * [2511] 最多可以摧毁的敌人城堡数目
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
    int captureForts(vector<int>& forts) {
        int cnt = 0;
        for (int i = 0; i < forts.size() ; ) {
            int j = i + 1;
            // cout << "i: " << i << " j: " << j << '\n'; 
            if (forts[i] != 0) {
                int x = forts[i];
                while (j < forts.size() && forts[j] == 0) j ++;
                if (j == forts.size()) return cnt;

                if (forts[j] == -x) {
                    cnt = max(cnt, j - i - 1);
                    i = j;
                    // cout << cnt << '\n';
                }
                else {
                    i = j;
                }
                
                
            }
            else i ++;
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,0,-1,0,0,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,-1]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1,1,-1,-1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,1,0]\n
// @lcpr case=end

 */

