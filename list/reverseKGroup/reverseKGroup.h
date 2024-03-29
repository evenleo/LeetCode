/*
* 题目：给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
*       k 是一个正整数，它的值小于或等于链表的长度。
*       如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
*
* 示例：
*       给定一个链表: 1->2->3->4->5
*       当 k = 2 时，应当返回: 2->1->4->3->5
*       当 k = 3 时，应当返回: 3->2->1->4->5
*
* 说明：
*      你的算法只能使用常数的额外空间。
*      你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        shared_ptr<ListNode> ptr(new ListNode(0));
        ptr.get()->next = head;
        ListNode* prev = ptr.get();
        ListNode* tail = ptr.get();
        while (1) {
            int count = k;
            while (count-- && tail) {
                tail = tail->next;
            }
            if (!tail) break;
            head = prev->next;
            while (prev->next != tail) {
                ListNode* cur = prev->next;
                prev->next = cur->next;
                cur->next = tail->next;
                tail->next = cur;
            }
            prev = head;
            tail = head;
        }
        return ptr.get()->next;
    }
};