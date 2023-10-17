/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=21917
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*当前节点是空
          当前节点是p
          当前节点是q  --> 返回当前节点
            pq在左右子树 --> 返回当前节点
            pq只在左子树 --> 递归左子树
            pq只在右子树 --> 递归右子树
            左右子树都找不到 --> 返回空*/
        if (root == nullptr || root == q || root == p) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        if (l) return l;
        return r;
        
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

