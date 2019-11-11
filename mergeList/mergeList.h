#include <vector>

using namespace std;

/*
* 题目：将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*
* 示例 1：
*        输入: 1->2->4, 1->3->4
*        输出: 1->1->2->3->4->4
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
    // 迭代方法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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

    /* 递归方法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    */
};

/*
* 题目：合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
*
* 示例 1：
*        输入: [
*                1->4->5,
*                1->3->4,
*                2->6
*              ]
*        输出: 1->1->2->3->4->4->5->6
*
*/


class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
    
    // 合并 k 个排序链表，巧用上面两个链表合并的方法
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        
        int step = lists.size();
        while (step != 1) {
            for (int i = 0; i < step/2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[step-1-i]);
            }
            step = step - step/2;
        }
        return lists[0];
    }
};