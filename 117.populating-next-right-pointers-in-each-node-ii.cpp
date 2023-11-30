/*
 * @lc app=leetcode.cn id=117 lang=cpp
 * @lcpr version=30104
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        vector<Node*> q = {root};
        while (!q.empty()){
            vector<Node*> nxt;
            for (int i = 0; i < q.size(); i ++) {
                Node* node = q[i];
                if (i) q[i - 1] ->next = node;
                if (node->left) nxt.push_back(node->left);
                if (node->right) nxt.push_back(node->right);
            }
            q = move(nxt);
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,null,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

