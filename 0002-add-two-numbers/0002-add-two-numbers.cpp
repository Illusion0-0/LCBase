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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(-1), *t1=l1, *t2=l2, *res=NULL;
        res=ans;
        int carry=0;
        while(t1 && t2){
            int res = t1->val+t2->val+carry;
            carry = res/10;
            ans->next = new ListNode(res%10);
            ans=ans->next;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
            int res = t1->val+carry;
            carry = res/10;
            ans->next = new ListNode(res%10);
            t1=t1->next;
            ans=ans->next;
        }
        while(t2){
            int res = t2->val+carry;
            carry = res/10;
            ans->next = new ListNode(res%10);
            t2=t2->next;
            ans=ans->next;
        }
        if(carry)ans->next=new ListNode(carry);
        return res->next;
    }
};