/*
 * @lc app=leetcode.cn id=112 lang=cpp
 * @lcpr version=21913
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr ) return false;
        //  存在左子树或右子树
        if (root->left || root->right) {
            targetSum -= root->val;
            // 计算左右子树的路径和
            bool l = hasPathSum(root->left, targetSum), r = hasPathSum(root->right, targetSum);
            return (l || r);
        }
        // 左右子树都没有
        return targetSum - root->val == 0 ? true : false;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

