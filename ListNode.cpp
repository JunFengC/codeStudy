/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* A = headA, * B = headB;  // 需要记录头节点
        while (A != B) {
            /*A = A->next != nullptr ? A->next : headB;
            B = B->next != nullptr ? B->next : headA;
            错误的写法，链表不相交，会陷入死循环*/
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};