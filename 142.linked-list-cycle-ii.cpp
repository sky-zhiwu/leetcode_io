/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=21913
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        // 环长 b+c
        // 慢指针距离 a+b
        // 快指针距离 a+b+k(b+c)
        // 2a+2b = a+b+k(b+c) --> a-c = (k-1)(b+c)
        // 时间复杂度O(n) 空间复杂度O(1)
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
            
        }
        return nullptr;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

