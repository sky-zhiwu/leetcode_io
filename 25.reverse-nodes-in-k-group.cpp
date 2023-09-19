/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=21913
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy;

        int n = 0; //n为链表节点数目
        while (cur) {
            n++;
            cur = cur->next;
        } 
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        cur = p0->next;
        
        while (n - k >= 0) {
            n -= k;
            for (int i = 0; i < k; i ++) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy->next;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

