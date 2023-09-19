/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=21913
 *
 * [257] 二叉树的所有路径
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

    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (node == nullptr) return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
            return ;
        }
        dfs(node->left, path + "->", res);
        dfs(node->right, path + "->", res); //回溯隐藏在了调用的参数中
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        dfs(root, path, res);
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

