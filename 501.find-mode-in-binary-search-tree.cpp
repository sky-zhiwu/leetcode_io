/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=21914
 *
 * [501] 二叉搜索树中的众数
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
    int pre = INT_MIN, cnt = 0, precnt = 0;
    vector<int> res;
    void dfs(TreeNode* node) { //中序
        if (node == nullptr) return ;
        dfs(node->left);
        if (pre == node->val) cnt ++;
        else {
            if (cnt >= precnt && pre != INT_MIN) {
                if (cnt > precnt) res.erase(res.begin(), res.end()), precnt = cnt;
                res.push_back(pre);
            }
            cnt = 1;
            pre = node->val;
        }
        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        // cout << " " << cnt << "\n";
        if (cnt >= precnt) {
            if (cnt > precnt) res.erase(res.begin(), res.end());
            res.push_back(pre);
        }
        return res;
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

