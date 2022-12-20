/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;
        map<Node*, Node*>m;
        while(temp){
            Node *copy = new Node(temp->val);
            m[temp]=copy;
            copy=NULL;
            free(copy);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp=temp->next;
        }
        return m[head];
    }
};