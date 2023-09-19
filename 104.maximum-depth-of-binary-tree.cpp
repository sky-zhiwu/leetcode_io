/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=21913
 *
 * [104] 二叉树的最大深度
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

    int res = 0;
    void f(TreeNode* root, int cnt) {
        if (root == nullptr) return ;
        cnt ++;
        res = max(res, cnt);
        f(root->left, cnt);
        f(root->right, cnt);
    }
    int maxDepth(TreeNode* root) {
        // 时间复杂度O(n) 空间复杂度O(n)
        // if (root == nullptr) return 0;
        // int l_depth = maxDepth(root->left);
        // int r_depth = maxDepth(root->right);
        // return max(l_depth, r_depth) + 1; //+1为了把当前节点算上

        f(root, 0);
        return res;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

