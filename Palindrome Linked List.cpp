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
    ListNode* reversedList(ListNode* a){
        if (a==NULL||a->next==NULL)return a;
        ListNode* par=a;
        ListNode* cur=a->next;
        ListNode* child=cur->next;
        par->next=NULL;
        while(cur->next){
            cur->next=par;
            par=cur;
            cur=child;
            child=child->next;
        }
        cur->next=par;
        return cur;
    }
    
    int getLength(ListNode* a){
        int len=0;
        while (a){
            a=a->next;
            len++;
        }
        return len;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL||head->next==NULL) return true;
        ListNode* cur =head;
        int len = getLength(head);
        for (int i=0;i<(len-1)/2;i++){
            cur=cur->next;
        }
        ListNode* mid=reversedList(cur->next);
        while(mid){
            if (mid->val!=head->val) return false;
            mid=mid->next;
            head=head->next;
        }
        return true;
    }
};
