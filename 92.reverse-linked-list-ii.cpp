/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=21913
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        //反转一段链表后，pre指向最后一个节点，cur指向最后节点的下一个节点
        //设置哨兵节点p0，p0->next->next = pre; p0->next = cur
        //特殊情况，left为1时，在head前面加上p0（哨兵节点）
        // 时间复杂度O(n) 空间复杂度O(1)

        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy;

        for (int i = 0; i < left - 1; i ++) p0 = p0->next;

        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        ListNode* cur = p0->next;

        int k = right - left + 1;
        while (k--) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        p0->next->next = cur;
        p0->next = pre;
        return dummy->next;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

