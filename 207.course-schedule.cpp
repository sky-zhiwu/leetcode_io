/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=21913
 *
 * [207] 课程表
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //拓扑排序
        int n = prerequisites.size(); //n为节点数目
        const int SIZE = numCourses;
        // int in[numCourses] = {0}; 
        vector<int> v[numCourses], in(numCourses, 0);
        for (int i = 0; i < n; i ++) { //遍历每个节点
            // cout << " " << prerequisites[i][1] << " " << prerequisites[i][0] << " \n";
            v[prerequisites[i][1]].push_back(prerequisites[i][0]); //学习i0之前要学习i1
            in[prerequisites[i][0]] += 1; //课程入度加1
            // cout << " " << in[prerequisites[i][0]] << " \n";
        }
        // for (int i = 0; i < numCourses; i ++) cout << " " << in[i] << " ";
        priority_queue<int, vector<int>, greater<int> > q;//设置优先队列 
        for (int i = 0; i < numCourses; i ++) {
            if (in[i] == 0) q.push(i);//入度为0的节点压入队列
        }
        while (!q.empty()) {
            int xx = q.top();
            cout << " " << xx << " " ;
            q.pop();
            numCourses --;
            for (int i = 0; i < v[xx].size(); i ++) {
                int yy = v[xx][i];
                in[yy] --;
                if (!in[yy]) q.push(yy);
            }
        }
        if (numCourses) {
            cout << numCourses;
            return false;
        } 
        else return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

