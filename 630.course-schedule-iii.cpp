/*
 * @lc app=leetcode.cn id=630 lang=cpp
 * @lcpr version=21913
 *
 * [630] 课程表 III
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
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        int sum = 0, day = 0;

        
        //最大堆
        priority_queue<int> q;

        for (auto &c: courses) {
            int duration = c[0], lastday = c[1];
            if (day + duration <= lastday) { //可以学习
                day += duration;
                q.push(duration); //放入最大堆
            }else if (!q.empty() && duration < q.top()) {
                day -= q.top() - duration;
                q.pop();
                q.push(duration);
            }
            
        }
        return q.size();
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,15],[3,19],[6,7],[2,10],[5,16],[8,14],[10,11],[2,19]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[4,3]]\n
// @lcpr case=end

 */

