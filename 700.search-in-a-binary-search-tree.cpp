/*
 * @lc app=leetcode.cn id=700 lang=cpp
 * @lcpr version=21914
 *
 * [700] 二叉搜索树中的搜索
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

    TreeNode* searchBST(TreeNode* root, int val) {
        //先序遍历
        if (root == nullptr || root->val == val) return root;
        return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

