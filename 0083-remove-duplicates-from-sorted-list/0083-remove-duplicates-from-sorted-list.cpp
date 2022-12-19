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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *f=head,*s=head;
        f=f->next;
        while(f!=NULL){
            if(s->val==f->val){
                s->next = f->next;
                f->next = NULL;
                f = s->next;
            }
            else{
                s = s->next;
                f = f->next;
            }
        }
        return head;
    }
};