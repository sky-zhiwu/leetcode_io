/*
 * @lc app=leetcode.cn id=103 lang=cpp
 * @lcpr version=21917
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        bool flag = true;
        vector<vector<int>> res;
        vector<TreeNode*> cur{root};
        while (cur.size() != 0) {
            vector<TreeNode*> nxt;
            vector<int> vals;
            for (auto r : cur) {
                vals.push_back(r->val);
                if (r->left) nxt.push_back(r->left);
                if (r->right) nxt.push_back(r->right);
            }
            cur = nxt;
            if (!flag) reverse(vals.begin(), vals.end());
            res.push_back(vals);
            flag = !flag;
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

