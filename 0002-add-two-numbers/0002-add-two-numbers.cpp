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
        ListNode *ans=new ListNode(-1), *res=NULL;
        res=ans;
        int carry=0, sum=0;
        while(l1 || l2){
            int a=0,b=0;
            if(l1)a = l1->val;
            if(l2)b = l2->val;
            sum = a + b + carry;
            carry = sum/10;
            ans->next = new ListNode(sum%10);
            ans=ans->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry)ans->next=new ListNode(carry);
        return res->next;
    }
};