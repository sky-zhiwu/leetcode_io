/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 * @lcpr version=21913
 *
 * [1123] 最深叶节点的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct TreeNode {
//      int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    int depth(TreeNode *node) {
        if (!node) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {//递归函数
        if (!root) return root;
        int d1 = depth(root->left), d2 = depth(root->right);
        if (d1 > d2) return lcaDeepestLeaves(root->left);
        if (d1 < d2) return lcaDeepestLeaves(root->right);
        return root;
    } 
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,3,null,2]\n
// @lcpr case=end

 */

