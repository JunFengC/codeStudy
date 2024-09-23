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
        ListNode* A = headA, * B = headB;  // ��Ҫ��¼ͷ�ڵ�
        while (A != B) {
            /*A = A->next != nullptr ? A->next : headB;
            B = B->next != nullptr ? B->next : headA;
            �����д���������ཻ����������ѭ��*/
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};