/*
 * @lc app=leetcode.cn id=129 lang=cpp
 * @lcpr version=21913
 *
 * [129] 求根节点到叶节点数字之和
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
#include<cmath>
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
    int sum = 0;
    
    void dfs(TreeNode* node, int x) {
        if (node == nullptr) return ;
        x = x * 10 + node->val;
        if (!node->left && !node->right) {
            sum += x;
            return ;

        }
        dfs(node->left, x);
        dfs(node->right, x);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [9,4,9,0,5,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,null,4,null,7,null,4,null,8,null,3,null,6,null,4,null,7,null]\n
// @lcpr case=end

 */

