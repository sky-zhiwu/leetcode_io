/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=21913
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* node0 = dummy;
        ListNode* node1 = head;
        ListNode* nxt = nullptr;
        while (node1 && node1->next) {
            nxt = node1->next->next;
            node0->next = node1->next;
            node1->next->next = node1;
            node1->next = nxt;

            node0 = node1;
            node1 = node0->next;
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

