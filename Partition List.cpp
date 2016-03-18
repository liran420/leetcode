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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* cur=head;
        ListNode* prev=&dummy;
        ListNode* last=&dummy;
        while(cur){
            if (cur->val<x){
                if(last->next!=cur){
                    ListNode*temp=cur->next;
                    cur->next=last->next;
                    last->next=cur;
                    prev->next=temp;
                    cur=temp;
                    last=last->next;
                }
                else{
                    prev=cur;
                    last=cur;
                    cur=cur->next;
                    
                }
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        return dummy.next;
    }
};
