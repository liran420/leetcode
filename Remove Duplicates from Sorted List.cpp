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
        if (head==NULL||head->next==NULL)return head;
        ListNode* pre = head; 
        ListNode* cur = head->next; 
        while(pre&&cur){
            if (pre->val==cur->val){
                pre->next=cur->next;
                cur=cur->next;
            }
            else{
                pre=pre->next;
                cur=cur->next;
            }
        }
        return head;
        
    }
};
