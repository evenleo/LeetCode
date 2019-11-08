/*
* 题目：在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
*
* 示例 1：
*        输入: 4->2->1->3
*        输出: 1->2->3->4
*
* 示例 2：
*        输入: -1->5->3->4->0
*        输出: -1->0->3->4->5
*
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reverse = NULL;
        ListNode *next;
        while (head != NULL) {
            next = head->next;
            head->next = reverse;
            reverse = head;
            head = next;
        }
        return reverse;
    }
};