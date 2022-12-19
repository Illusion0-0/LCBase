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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        ListNode *temp = head, *test = NULL, *addr = NULL, *tempnode = NULL, *oknode = NULL, *newhead = NULL;
        int len = 0, ind = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        int reach = (len / k) * k;
        temp = head;
        while (ind < reach)
        {
            ind++;
            if (ind % k == 1)
            {
                addr = NULL;
                tempnode = temp;
            }
            test = temp->next;
            temp->next = addr;
            addr = temp;
            if (ind % k == 0 && (ind / k) % 2 != 0)
            {
                if (ind / k != 1)
                    oknode->next = temp, oknode = tempnode;
                else
                    oknode = tempnode;
            }
            if (ind % k == 0 && (ind / k) % 2 == 0)
            {
                oknode->next = temp;
                oknode = tempnode;
            }
            if (ind % k == 0 && ind / k == 1)
                newhead = temp;
            temp = test;
        }
        // oknode->next = temp;
        tempnode->next = temp;
        return newhead;
    }
};