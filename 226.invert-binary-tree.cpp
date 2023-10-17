/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=21913
 *
 * [226] 翻转二叉树
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:

    void f(TreeNode* node, TreeNode* res) {
        res->val = node->val;
        if (node->right) {
            res->left = new TreeNode();
            f(node->right, res->left);
        }
        if (node->left) {
            res->right = new TreeNode();
            f(node->left, res->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res = new TreeNode();
        if (root == nullptr) return nullptr;
        f(root, res);
        return res;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

