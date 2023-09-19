/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 * @lcpr version=21913
 *
 * [1448] 统计二叉树中好节点的数目
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
    void dfs(TreeNode* node, int& cnt, int& maxnum, vector<int>& path) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (node->val >= maxnum) {
            cnt ++;
            maxnum = node->val;
        }
        dfs(node->left, cnt, maxnum, path);
        dfs(node->right, cnt, maxnum, path);
        path.erase(path.end() - 1);
        maxnum = *max_element(path.begin(), path.end());

    }
    int goodNodes(TreeNode* root, int mx = -1e5) {
        // int cnt = 0, maxnum = root->val;
        // vector<int> path;
        // dfs(root, cnt, maxnum, path);
        // return cnt;
        if (root == nullptr) return 0;
        int l = goodNodes(root->left, max(root->val, mx));
        int r = goodNodes(root->right, max(root->val, mx));
        return l + r + (mx <= root->val);  




    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,3,null,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,null,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

