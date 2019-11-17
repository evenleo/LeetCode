/*
* 题目：删除链表当前节点。请编写一个函数，使其可以删除某个链表中给定节点，你将只被给定要求被删除的节点。
*
* 示例 1：
*        输入: head = [4,5,1,9], node = 5
*        输出: [4,1,9]
*        解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
*/

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 这题目就是删除当前节点的意思
    void deleteNode(ListNode* node) {
        if (node->next == NULL) {
            node = NULL;
        } else {
            node->val = node->next->val;
            node->next = node->next->next;
        }
       
    }
};