/*
 * @lc app=leetcode.cn id=113 lang=cpp
 * @lcpr version=21913
 *
 * [113] 路径总和 II
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
    vector<int> path;
    vector<vector<int>> res;
    void dfs(TreeNode* node, int targetnum) {
        if (node == nullptr) return;
        path.push_back(node->val);

        if (!node->left && !node->right) { //叶子节点
            if (node->val == targetnum)  res.push_back(path);
            path.erase(path.end() - 1);
            return;
        }
        dfs(node->left, targetnum - node->val);
        dfs(node->right, targetnum - node->val);
        // 防止分支污染
        path.erase(path.end() - 1);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // 回溯
        dfs(root, targetSum);
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

