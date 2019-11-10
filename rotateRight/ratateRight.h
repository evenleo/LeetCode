/*
* 题目：给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
*
* 示例 1：
*        输入: 1->2->3->4->5->NULL, k = 2
*        输出: 4->5->1->2->3->NULL
*        解释：向右旋转 1 步: 5->1->2->3->4->NULL
*              向右旋转 2 步: 4->5->1->2->3->NULL
*
*        注意：k 可能大于链表的长度
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        
        ListNode* tail = head;
        ListNode* node = head;
        int len = 1;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        len = len - (k % len);
        tail->next = head;
        while (--len) {
            node = node->next;
        }
        head = node->next;
        node->next = NULL;
        return head;
    }
};