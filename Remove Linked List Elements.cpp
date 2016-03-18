/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* cur=&dummy;
        ListNode* temp = cur->next;
        while (cur->next!=NULL){
            if(temp->val!=val){
                cur=cur->next;
                temp=temp->next;
            }
            else{
                ListNode*del=cur->next;
                cur->next=cur->next->next;
                delete (del);
                temp=cur->next;
            }
        }
        return dummy.next;
        
    }
};
