/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=21913
 *
 * [445] 两数相加 II
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* reverse(ListNode* head) { //反转
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        ListNode* cur = head;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        ListNode* node1 = l1, *node2 = l2; 
        int c = 0;
        vector<int> s;
        while (node1 || node2) {
            int sum;
            if (node1 && node2) sum = node1->val + node2->val;
            else if (node1) sum = node1->val;
            else sum = node2->val;
            s.push_back((sum + c) % 10);
            // cout << c <<  " "  << sum % 10 + c << "   " << sum << "\n";
            c = (sum + c) / 10;
            if (node1) node1 = node1->next;
            if (node2) node2 = node2->next;
        }
        if (c) s.push_back(c);
        
        ListNode* res = new ListNode(0);
        ListNode* rr = res;
        for (int i = s.size() - 1; i >= 0; i --) {
            ListNode* r = new ListNode(s[i], nullptr);
            
            rr->next = r;
            rr = r;
        }
        return res->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

