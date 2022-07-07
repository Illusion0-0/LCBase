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
    ListNode *reverse(ListNode *head){
        if(head==NULL)return NULL;
        ListNode *p=NULL,*c=head,*n=head->next;
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)n=n->next;
        }
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp=head,*p=head,*s=head,*e=head;
        if(left==right)return head;
        for(int i=1;i<left;i++){
            if(i==left-1)p=head;
            head=head->next;
            s=head;
        }
        for(int i=1;i<right-left+1;i++){
            head=head->next;
            e=head;
        }
        ListNode *last=e->next,*kk=NULL;
        e->next=NULL;
        kk=s;
        ListNode *val = reverse(s);
        kk->next=last;
        if(p!=kk)p->next=val;
        else temp=val;
        ListNode* t=temp;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
        return t;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int r=1,i=1,l=k-1;
        ListNode * temp=head,*temp2=head,*t=head,*p=head;
        int sz=0;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        while(l--){
            temp2=temp2->next;
        }
        while(r+k-1<=sz){
            
            if(i%k==0){
                cout<<t->val<<" "<<r<<" "<<r+k-1<<endl;
                ListNode * ptr = reverseBetween(t,r,r+k-1);
                r+=k;
                t=ptr;
            }
            i++;
        }
        return temp2;
        
    }
};