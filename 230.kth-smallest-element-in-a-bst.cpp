/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=21914
 *
 * [230] 二叉搜索树中第K小的元素
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
    int cnt = 0, res = -1;
    void f(TreeNode* node, int k) {
        if (node == nullptr) return;
        f(node->left, k);
        cnt ++;
        if (cnt == k) {
            res = node->val;
            return ;
        }
        f(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root, k);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */

