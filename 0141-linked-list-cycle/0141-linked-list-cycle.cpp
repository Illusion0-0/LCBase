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
    bool hasCycle(ListNode *head) {
        bool flag=false;
        if(head==NULL || head->next==NULL)return flag;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val==INT_MIN){flag=true;break;}
            temp->val=INT_MIN;            
            temp=temp->next;
        }
        return flag;
    }
};