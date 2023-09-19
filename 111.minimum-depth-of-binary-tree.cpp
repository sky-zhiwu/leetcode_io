/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=21913
 *
 * [111] 二叉树的最小深度
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
   int depth(TreeNode* node) {
        if (node == nullptr) return 0;
        int l = depth(node->left), r = depth(node->right);
        if (node->left && node->right) return 1 + min(l, r);
        else if (!node->left) return 1 + r;
        else return 1 + l;
   }
    int minDepth(TreeNode* root) {
        // if (root == nullptr) return 0; 
        // if (root->left && root->right) return 1 + min(minDepth(root->left), minDepth(root->right));
        // return 1 + max(minDepth(root->left), minDepth(root->right));
        return depth(root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */

