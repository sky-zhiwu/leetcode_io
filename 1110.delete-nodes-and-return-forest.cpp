/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 * @lcpr version=21913
 *
 * [1110] 删点成林
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
    vector<TreeNode*> res;
    unordered_set<int> set;
    TreeNode* dfs(TreeNode* node) { //后序遍历
        if (node == nullptr) return nullptr;
        node->left = dfs(node->left); // 左子树为递归左子树返回值
        node->right = dfs(node->right); // 右子树为递归右子树返回值
        if (set.count(node->val) == 0) { //不用删除
            return node;
        }
        if (node->left) res.push_back(node->left);
        if (node->right) res.push_back(node->right);
        return nullptr;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set.insert(to_delete.begin(), to_delete.end());
        if (dfs(root)) res.push_back(root); // 如果根节点没被删除，则加入答案
        return res;




        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n[3,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,null,3]\n[3]\n
// @lcpr case=end

 */

