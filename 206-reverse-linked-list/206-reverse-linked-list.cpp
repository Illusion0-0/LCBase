/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode *p=NULL,*c=head,*n=head->next;
        while(n!=NULL){
            c->next=p;
            p=c;
            c=n;
            n=c->next;
        }
        c->next=p;
        return c;
        //while(c->next!=NULL) 
    }
};