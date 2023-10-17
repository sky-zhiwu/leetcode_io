/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=21914
 *
 * [98] 验证二叉搜索树
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
#include<cmath>
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
    // 前序遍历
    // bool check(int x, long l, long r) {
    //     return (x > l && x < r);
    // }
    
    // bool isValidBST(TreeNode* root, long l = -pow(2, 31) - 1, long r = pow(2, 31) + 1) {
    //     if (root == nullptr) return true;
    //     return check(root->val, l, r) && isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r);
    // }

    // 中序遍历，二叉搜索树有序
    // long pre = -2147483649; //第一个节点pre为负无穷
    // bool isValidBST(TreeNode* root) {
    //     if (root == nullptr) return true;
    //     if (!isValidBST(root->left)) return false; //递归左子树
    //     if (pre >= root->val) return false;
    //     pre = root->val;
    //     return isValidBST(root->right);
    // }

    // 后序遍历
    pair<long, long> f(TreeNode* node) {
        if (node == nullptr) return {2147483648, -2147483649};
        long x = node->val;
        pair<long, long> l = f(node->left);
        if (x <= l.second) return {-2147483649, 2147483648};
        pair<long, long> r = f(node->right);
        if (x >= r.first) return {-2147483649, 2147483648};
        long ll = min(l.first, x), rr = max(x, r.second);
        return {ll, rr};
    }
    bool isValidBST(TreeNode* root) {
        return f(root).second != 2147483648;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

