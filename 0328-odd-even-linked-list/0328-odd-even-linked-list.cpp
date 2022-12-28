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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *temp=head,*start=head;
        int a=0,b=0;
        while(temp->next){
            a++;
            temp=temp->next;
        }
        while(b<a && start->next && start->next->next){
            b+=2;
            ListNode *ok = start->next;
            start->next = start->next->next;
            start = start->next;
            temp->next = new ListNode(ok->val);
            temp = temp->next;
        }
        return head;
    }
};