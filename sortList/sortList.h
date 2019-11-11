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
    
    template<class T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    
    // 合并链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
       shared_ptr<ListNode> ptr = make_shared<ListNode>(0);  // 用shared_ptr可自动析构头结点
        ListNode* list = ptr.get();
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                list->next = l1;
                l1 = l1->next;
            } else {
                list->next = l2;
                l2 = l2->next;
            }
            list = list->next;
        }
        
        if (l1 != NULL) list->next = l1;
        if (l2 != NULL) list->next = l2;
        
        return ptr.get()->next;
    }

    // 切割头结点，即将头结点与原链表分类并返回
    ListNode* spiceHead(ListNode*& head) {
        ListNode* pos = head;
        head = head->next;
        pos->next = NULL;
        return pos;
    }
   

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;
        
        ListNode* carry;
        ListNode* counter[64];
        int refill = 0;

        while (head) {
            carry = spiceHead(head);
            int i = 0;
            while (i < refill && counter[i]) {
                counter[i] = merge(carry, counter[i]);
                carry = NULL;
                swap(carry, counter[i++]);
            }
            swap(carry, counter[i]);
            if (i == refill) refill++;
        }

        for (int i = 1; i < refill; ++i) {
            counter[i] = merge(counter[i], counter[i-1]);
        }
        
        return counter[refill-1];
    }
};