/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=21913
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 时间复杂度O(链表长度) 空间复杂度O(1)
        ListNode* dummy = new ListNode(0, head);
        ListNode *left = dummy, *right = dummy;
        for (int i = 0; i < n; i ++) right = right->next;
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy->next;
        




    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

