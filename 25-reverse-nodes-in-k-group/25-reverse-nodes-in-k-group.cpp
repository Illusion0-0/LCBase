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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>v;
        int sz=0;
        ListNode *temp=head,*temp2=head;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
            sz++;
        }
        for(int i=0;i<sz;i+=k){
            if(i+k<=sz)reverse(v.begin()+i,v.begin()+i+k);
        }
        for(int i:v){
            // cout<<i<<" ";
            temp->val=i;
            temp=temp->next;
        }
        return temp2;
    }
};