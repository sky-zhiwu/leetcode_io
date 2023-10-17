/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=21917
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 时间复杂度O(n) 空间复杂度O(n)
        if (root == nullptr) return {};
        vector<vector<int>> res;
        // 使用队列
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> vals;
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                TreeNode* f = q.front();
                vals.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                q.pop();
            }
            res.push_back(vals);
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

