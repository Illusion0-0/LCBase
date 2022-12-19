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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*temp1=list1,*temp2=list2,*ans=new ListNode(-1);
        ListNode *res = ans;
        while(temp1!=NULL || temp2!=NULL){
            if((temp1!=NULL && temp2==NULL) || (temp2!=NULL && temp1!=NULL && temp1->val<=temp2->val)){
                ans->next=temp1;
                ans=ans->next;
                temp1=temp1->next;
            }
            else{
                ans->next=temp2;
                ans=ans->next;
                temp2=temp2->next;
            }
        }
        return res->next;
    }
};