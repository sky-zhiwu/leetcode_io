/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=21913
 *
 * [110] 平衡二叉树
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
        int l = depth(node->left);
        if (l == -1) return -1;
        int r = depth(node->right);
        if (r == -1 || abs(l-r) > 1) return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) == -1 ? false : true;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

