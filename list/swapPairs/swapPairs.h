/*
* 题目：给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
*      你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*
* 示例：
*       给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        shared_ptr<ListNode> ptr = make_shared<ListNode>(0);
        ptr.get()->next = head;
        ListNode* list = ptr.get();
        while (list->next && list->next->next) {
            ListNode* a = list->next;
            ListNode* b = list->next->next;
            a->next = b->next;
            b->next = a;
            list->next = b;
            list = a;
        }
        return ptr.get()->next;
    }
};