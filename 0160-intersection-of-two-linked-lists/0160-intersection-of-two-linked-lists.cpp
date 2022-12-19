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
    int lenf(ListNode *head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA, *q=headB;
        int len1 = lenf(p), len2 = lenf(q);
        while(len1>len2){
            len1--,p=p->next;
        }
        while(len2>len1){
            len2--,q=q->next;
        }
        while(p!=q){
            p = p->next;
            q = q->next;
        }
        return p;
        
    }
};