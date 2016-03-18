/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* a){
        int temp=0;
        while (a){
            a=a->next;
            temp++;
        }
        return temp;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if (lenB < lenA){
            for (int i=0;i<lenA-lenB;i++){
                headA=headA->next;
            }
        }
        if (lenA < lenB){
            for (int i=0;i<lenB-lenA;i++){
                headB=headB->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
