/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 * @lcpr version=21913
 *
 * [1026] 节点与其祖先之间的最大差值
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
    void f(TreeNode* node, int& res, vector<int>& path) {
        if (node == nullptr) return ;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            int maxnum = *max_element(path.begin(), path.end());
            int minnum = *min_element(path.begin(), path.end());
            res = max(res, maxnum - minnum);
        }
        f(node->left, res, path);
        f(node->right, res, path);
        path.erase(path.end() - 1);

    }
    int maxAncestorDiff(TreeNode* root) {
        int res = -1;
        vector<int> path;
        f(root, res, path);
        return res;
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,3,10,1,6,null,14,null,null,4,7,13]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,null,0,3]\n
// @lcpr case=end

 */

