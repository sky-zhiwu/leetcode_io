/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=21913
 *
 * [199] 二叉树的右视图
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
    // 定义递归函数
    void f(TreeNode* node, int depth, vector<int>& res) {
        if (node == nullptr) return ;
        if (depth == res.size()) res.push_back(node->val);
        f(node->right, depth + 1, res); 
        f(node->left, depth + 1, res); 
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        f(root, 0, res);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

