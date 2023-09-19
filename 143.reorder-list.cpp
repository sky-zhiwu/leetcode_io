/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=21913
 *
 * [143] 重排链表
 */

// @lc code=start
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        // 时间复杂度O(n) 空间复杂度O(1)
        ListNode* mid = middle(head);
        ListNode* h2 = reverseList(mid);
        
        while (h2->next) {
            ListNode *n1 = head->next, *n2 = h2->next;
            head->next = h2;
            h2->next = n1;
            head = n1;
            h2 = n2;
        }
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

