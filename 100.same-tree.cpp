/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=21913
 *
 * [100] 相同的树
 */

// @lc code=start
#include<iostream>

#ifndef iostream
#define iostream

using namespace std;
//   Definition for a binary tree node.

 typedef struct tr {
     int val;
     TreeNode *left;
     TreeNode *right;
    //  TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //深度优先
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
  #endif
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */
