/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=21917
 *
 * [235] 二叉搜索树的最近公共祖先
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
        /*当前节点是空 (不用判断)
          当前节点是p
          当前节点是q 
          pq值在root两边 --> 返回当前节点
            pq小于root --> 递归左子树
            pq大于root --> 递归右子树*/
        int x = root->val;
        if  (p->val < x && q->val < x) return lowestCommonAncestor(root->left, p, q);
        if  (p->val > x && q->val > x) return lowestCommonAncestor(root->right, p, q);
        if (root == q || root == p) return root;
        return root;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

