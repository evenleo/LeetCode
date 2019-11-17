/*
* 题目：编写一个程序，找到两个单链表相交的起始节点。
*
* 示例 1：
*        输入: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], 
*        skipA = 2, skipB = 3
*        输出: Reference of the node with value = 8
*        输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，
*        链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；
*        在 B 中，相交节点前有 3 个节点。
*
* 注意：
*      如果两个链表没有交点，返回 null.
*      在返回结果后，两个链表仍须保持原有的结构。
*      可假定整个链表结构中没有循环。
*      程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //法1：求两链表的长度之差 n，长的链表先走 n 步，然后同时走判断是否有相同点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while (nodeA != NULL) {
            lenA++;
            nodeA = nodeA->next;
        }
        while (nodeB != NULL) {
            lenB++;
            nodeB = nodeB->next;
        }
        
        nodeA = headA;
        nodeB = headB;
        int n = lenA - lenB;
        if (n > 0) {
            while (n--) {
                nodeA = nodeA->next;
            }
        } else {
            while (n++) {
                nodeB = nodeB->next;
            }
        }
        
        while (nodeA != NULL && nodeB != NULL) {
            if (nodeA == nodeB) {
                return nodeA;
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return NULL;
    }

    // 法2: 分别从 A 和 B 链表头结点开始走，A 走到 NULL 就接着从 B 头结点走，
    // B 走到NULL 就接着从 A 头节点头走，即 A->NULL->B->NULL 和 B->NULL->A->NULL 两个方向
    // 此过程节点相等就退出循环，只存在两种情况：1.找到相交节点，2.两方向走到头,均为NULL，
    // 是最佳方法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while (nodeA != nodeB) {
            nodeA = nodeA ? nodeA->next : headB;
            nodeB = nodeB ? nodeB->next : headA;
            // 不能用下面这样:
            // nodeA = nodeA->next ? nodeA->next : headB;
            // nodeB = nodeB->next ? nodeB->next : headA;
            // 上面两个链表会连在一起，貌似更合理，但如果输出的两条链表无交点则不满足，
            // 所以都引入一个空节点可避免上述问题，当同时走完两链表时nodeA和nodeB都为NULL，退出循环
        }
        return nodeA;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) 
            return NULL;
        
        // 让A首尾相连成环，变为求环入口节点的问题
        ListNode* tailA = headA;
        while (tailA->next != NULL) {
            tailA = tailA->next;
        }
        tailA->next = headA;
        
        ListNode* slow = headB;
        ListNode* fast = headB;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                break;
        }
        
        if (fast == NULL || fast->next == NULL) {
            // 满足此条件即链表无环
            tailA->next = NULL;  // 恢复A链表的形状
            return NULL;
        } 
        
        fast = headB;
        while (1) {
            if (slow == fast) {
                tailA->next = NULL;  // 恢复A链表的形状
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
};