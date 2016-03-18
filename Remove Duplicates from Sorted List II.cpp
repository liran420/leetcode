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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* ins=&dummy;
        ListNode* cur=head;
        while(cur){
            bool isDup= false;
            while(cur->next&&cur->val==cur->next->val){
                isDup=true;
                ListNode* temp=cur;
                cur=cur->next;
                delete(temp);
            }
            if (isDup){
                    ListNode*temp=cur;
                    cur=cur->next;
                    delete temp;
                    continue;
                }
                ins->next=cur;
                ins=ins->next;
                cur=cur->next;
        }
        ins->next=cur;
        return dummy.next;
    }


};
