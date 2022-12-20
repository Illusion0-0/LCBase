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
    // code for merging 2 sorted linked lists
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
    // Using simple merge-sort merging technique
    // Time Complexity: O(nlogk) < O(n*k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode *l1=NULL, *l2=NULL;
        while(lists.size()>1){
            vector<ListNode*>ans;
            for(int i=0;i<lists.size();i+=2){
                l1 = lists[i];
                if(i+1<lists.size())l2 = lists[i+1];
                else l2 = NULL;
                ans.push_back(mergeTwoLists(l1,l2));
            }
            lists=ans;
        }
        return lists[0];
    }
};