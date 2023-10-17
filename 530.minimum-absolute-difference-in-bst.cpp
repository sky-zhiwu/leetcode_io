/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=21914
 *
 * [530] 二叉搜索树的最小绝对差
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
    int pre = INT_MIN, res = 1e5 + 10; 
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        if (pre != INT_MIN) res = min(res, abs(pre - node->val));
        pre = node->val;
        dfs(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        // 中序
        dfs(root);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */

