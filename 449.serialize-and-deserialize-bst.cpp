/*
 * @lc app=leetcode.cn id=449 lang=cpp
 * @lcpr version=21913
 *
 * [449] 序列化和反序列化二叉搜索树
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include<cstring>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };
class Codec {
public:
    
    string res;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { //后序遍历
        if (root == NULL) return "";
        serialize(root->left);
        serialize(root->right);
        string str = to_string(root->val); 
        // cout << str << "  ";
        res.append(str); res.push_back(',');
        return res; 
    }

    // Decodes your encoded data to tree.
    TreeNode* ans;
    // TreeNode* buildTreeH(vector<int> &s, int l, int r, nordered_map<int, int> index_map) {
    //     if (s.size() == 0) return ans;
    //     ans->val = *s.end();
    //     s.erase(s.end());
    //     for (int i = 0; i < s.size(); i ++) {
    //         if (s[i] > ans->val) {l = i - 1; break;}
    //     }
    //     ans->left = buildTreeH(s, 0, l);
    //     ans->right = buildTreeH(s, l + 1, s.size() - 1);
    //     return ans;

    // }

    TreeNode* buildTreeH(vector<int> &s, int l, int r, unordered_map<int, int>& index_map) {
        if (l > r) { //l, r为hou序序列的左右端点
        return nullptr;
    }

    int root_val = s[r]; //后序中的最后一个数为根节点
    TreeNode* root = new TreeNode(root_val);
    
    int root_index = index_map[root_val];
    cout << root_index << "  ";

    int left_size = root_index - l;
    int right_size = r - root_index ;
    cout << left_size << right_size << "  ";
    root->left = buildTreeH(s, l, l + left_size - 1, index_map);
    root->right = buildTreeH(s, r - 1 - right_size, r - 1, index_map);

    return root;

    }

    TreeNode* buildTree(vector<int> &s) { //s为后序遍历的数组
        int n = s.size();
        vector<int> s1 = s; sort(s1.begin(),s1.end()); ////s1为中序遍历的数组
        unordered_map<int, int> index_map;
        for (int i = 0; i < n; ++i) {
            cout << s1[i] << ' ';
            index_map[s1[i]] = i;
        }
        return buildTreeH(s, 0, n - 1, index_map);
    }
    TreeNode* deserialize(string data) {
        vector<int> res;
        
        int x = 0;
        cout << data << "  ";
        for (int i = 0; i < data.size(); i ++) {
            // cout << i << " : " << data[i] << "  ";
            // cout << data[i] - '0' << ' ';
            if (data[i] == ',') res.push_back(x), x = 0;
            else x = x * 10 + (data[i] - '0');
            
        }
        // cout << res.size() << ' ';
        // for (int i = 0; i < res.size(); i ++) {
        //     cout << i << " : " << res[i] << "  ";
        // }
        return buildTree(res);

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [8,3,10,1,6]\n
// @lcpr case=end

 */

