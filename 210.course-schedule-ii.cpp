/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=21913
 *
 * [210] 课程表 II
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //拓扑排序
        vector<int> res;
        int n = prerequisites.size(); //n为节点数目
        
        vector<int> v[numCourses], in(numCourses, 0);
        for (int i = 0; i < n; i ++) { //遍历每个节点
        
            v[prerequisites[i][1]].push_back(prerequisites[i][0]); //学习i0之前要学习i1
            in[prerequisites[i][0]] += 1; //课程入度加1
            
        }
        // for (int i = 0; i < numCourses; i ++) cout << " " << in[i] << " ";
        
        priority_queue<int, vector<int>, greater<int> > q;//设置优先队列 
        for (int i = 0; i < numCourses; i ++) {
            if (in[i] == 0) q.push(i);//入度为0的节点压入队列
        }
        while (!q.empty()) {
            int xx = q.top();
            res.push_back(xx);
            
            q.pop();
            
            for (int i = 0; i < v[xx].size(); i ++) {
                int yy = v[xx][i];
                in[yy] --;
                if (!in[yy]) q.push(yy);
            }
        }
        
        if (res.size() == numCourses) return res;
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

