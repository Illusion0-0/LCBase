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
        while(t1 || t2){
            int a=0,b=0, res=0;
            if(t1)a = t1->val;
            if(t2)b = t2->val;
            res = a + b + carry;
            carry = res/10;
            ans->next = new ListNode(res%10);
            ans=ans->next;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
        if(carry)ans->next=new ListNode(carry);
        return res->next;
    }
};