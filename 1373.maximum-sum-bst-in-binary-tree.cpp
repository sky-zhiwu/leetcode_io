/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 * @lcpr version=21914
 *
 * [1373] 二叉搜索子树的最大键值和
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
    
    pair<pair<int, int>, int> f(TreeNode* node) {
        if (node == nullptr) return {{INT_MAX, INT_MIN}, 0};
        int x = node->val;
        pair<pair<int, int>, int> l = f(node->left);
        pair<pair<int, int>, int> r = f(node->right);
        if (x <= l.first.second || x >= r.first.first) return {{INT_MIN, INT_MAX}, 0};
        int sum = x + l.second + r.second;
        res = max(sum, res);
        int ll = min(l.first.first, x), rr = max(x, r.first.second);
        return {{ll, rr},sum};
    }
    int maxSumBST(TreeNode* root) {
        f(root);
        return res;

        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [-2,-2,-3,9,10,-4,2,null,null,9,7,null,-7,null,-2,9,null,1,13,9,null,-3,8,null,null,-5,5,8,15,6,null,1,null,null,3,null,null,null,6,null,10,null,20,7,null,null,null,-4]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-2,-5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,3,null,6,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,null,6,3,9,null,-4,4,null,null,null,-3,null,10]\n
// @lcpr case=end

 */

