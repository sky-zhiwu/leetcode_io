/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 * @lcpr version=21914
 *
 * [1372] 二叉树中的最长交错路径
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
    int  res = 0;
    void dfs(TreeNode* node, bool direction, int cnt) { //0左1右
        if (node == nullptr) return;
        res = max(res, cnt + 1) ;
        if (!direction) { //下一步往左
            dfs(node->left, 1, cnt + 1);
            dfs(node->right, 0, 1);
        }
        else { 
            dfs(node->right, 0, cnt + 1);
            if (node->left) dfs(node->left, 1, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, 0, 0); // 从根节点左子树出发
        dfs(root, 1, 0);  
        return res - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,1,1,1,null,null,1,1,null,1,null,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,null,1,null,null,1,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

