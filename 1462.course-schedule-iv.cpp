/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 * @lcpr version=21913
 *
 * [1462] 课程表 IV
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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = prerequisites .size();
        vector<int> v[numCourses], in(numCourses, 0);
        for (int i = 0; i < n; i ++) {
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]] ++;
        }
        // priority_queue<int, vector<int>, greater<int> > q; //升序队列
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (in[i] == 0) q.push(i);
        }
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false) );
        while (!q.empty()) {
            int xx = q.front();
            q.pop();
            for (auto& x : v[xx]) {
                isPre[xx][x] = true;
                for (int i = 0; i < numCourses; i ++) {
                    isPre[i][x] = isPre[i][x] | isPre[i][xx];
                }
                in[x] --;
                if (in[x] == 0) q.push(x);
            }
        }
        vector<bool> res;
        for (auto c : queries) {
            res.push_back(isPre[c[0]][c[1]]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[0,1],[1,2],[2,3],[3,4]]\n[[0,4],[4,0],[1,3],[3,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,0],[2,0]]\n[[1,0],[1,2]]\n
// @lcpr case=end

 */

