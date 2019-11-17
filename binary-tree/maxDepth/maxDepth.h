/*
* 题目：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
*
* 示例：
*       给定一个链表: 1->2->3->4->5, 和 n = 2.
*       当删除了倒数第二个节点后，链表变为 1->2->3->5.
*
* 说明：给定的 n 保证是有效的。
*
* 进阶：你能尝试使用一趟扫描实现吗？
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) return head;

        ListNode* preK = head;
        ListNode* list = head;
        int k = 0;
        while (list->next != NULL) {
            if (k < n) {
                k++;
            } else {
                preK = preK->next;
            }
            list = list->next;
        }
        if (k == n) {  //此时prek指向的是要删除的目标节点的前续节点
            ListNode* tmp = preK->next;
            preK->next = preK->next->next;
            delete tmp;
        } else if (k == n-1) {  //当k为n-1，差一步，此时prek肯定指向head,该删除head节点
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        } 
        return head;
    }
};