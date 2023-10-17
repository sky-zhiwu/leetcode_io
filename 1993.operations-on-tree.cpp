/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 * @lcpr version=21917
 *
 * [1993] 树上的操作
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
class LockingTree {
private:
    int n;
    vector<vector<int>> son;
    unordered_map<int, tuple<bool, int, int>> locked;

public:
    LockingTree(vector<int>& parent) {
        n = parent.size();
        son = vector<vector<int>>(n, vector<int>(2, -1)); // n表示共n个节点，2为左右孩子，初始化-1
        for (int i{0}; i < n; i ++) {
            locked[i] = {false, 0, parent[i]}; // 未上锁，0表示无上锁用户，父节点
            if (parent[i] != -1) {
                son[parent[i]].push_back(i); // parent[i]的子节点
            }
        }
    }
    
    bool lock(int num, int user) {
        if (get<0>(locked[num])) return false; //已经上过锁了
        get<0>(locked[num]) = true; //否则就上锁
        get<1>(locked[num]) = user; //user为上锁者
        return true;
    }
    
    bool unlock(int num, int user) {
        if (!get<0>(locked[num]) || get<1>(locked[num]) != user) 
            return false; //没上过锁或者不是user上的锁
        get<0>(locked[num]) = false;
        get<1>(locked[num]) = 0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        /*1指定节点当前状态为未上锁
          2.指定节点至少有一个上锁状态的子孙节点
          3.指定节点没有任何上锁的祖先节点*/

        int pre = num; // 看pre是否能回溯到根节点,即满足条件3 || 1
        while (!get<0>(locked[pre]) && pre >= 0) {
            pre = get<2>(locked[pre]);
        }
        if (pre != -1) return false; //不满足3 || 1

        int res{false}; //初始化没有上锁的子孙节点
        // bfs
        queue<int> q;
        for (int i{0}; i < n; i ++) {
            if(get<2>(locked[i]) == num) 
                q.push(i); //寻找当前节点的子节点
        }
        while (!q.empty()) {
            int f = q.front(); // f为子节点
            q.pop();
            if (get<0>(locked[f])) { //子节点上锁了，就解锁
                res = true; //存在上锁的子节点
                get<0>(locked[f]) = false;
                get<1>(locked[f]) = 0;
            }
            for (auto x : son[f]) { //x为f的子节点
                if (x != -1) q.push(x); // 如果存在子节点就继续检查
            }
        }
        if (res)lock(num, user);
        return res;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end



/*
// @lcpr case=start
// ["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"][[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]\n
// @lcpr case=end

 */

