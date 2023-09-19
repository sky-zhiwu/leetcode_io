/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=21913
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 时间复杂度O(n) 空间复杂度O(1)
        if (head == nullptr) return nullptr;

        ListNode* cur = head;
        // 如果下一个节点存在并且和cur值相同就删除
        while (cur->next) {
            if (cur->next->val == cur->val) cur->next = cur->next->next;
            // 否则移到下一个节点
            else cur = cur->next;
        }
        return head;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */

