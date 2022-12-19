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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        ListNode *temp=head, *ok=NULL, *ans=new ListNode(-1);
        ListNode *res=ans;
        while(temp!=NULL){
            if(temp->val==val){
                ans->next = temp->next;
                ok = temp->next;
                temp->next=NULL;
                temp = ok;
            }
            else{ 
                ans->next=temp;
                ans = ans->next;
                temp=temp->next;
            }
        }
        return res->next;
    }
};