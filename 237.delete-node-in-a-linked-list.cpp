/*
 * @lc app=leetcode.cn id=237 lang=cpp
 * @lcpr version=21913
 *
 * [237] 删除链表中的节点
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
    void deleteNode(ListNode* node) {
        // 脑筋急转弯 把node的后一个节点复制给它，把后一个节点删除（因为node不是最后一个节点）
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */

