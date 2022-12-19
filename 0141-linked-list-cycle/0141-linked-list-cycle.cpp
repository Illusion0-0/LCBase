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
        ListNode *f=head, *s=head, *e=head;
        while(s && f && s->next && f->next && f->next->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                while(s!=e){
                    s=s->next;
                    e=e->next;
                }
                return e;
            }
        }
        return NULL;
    }
};