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
    ListNode* reverseNodes(ListNode* head, int k)
    {
        ListNode* dummy = new ListNode(0,head);
        ListNode* prevG = dummy;

        while(true)
        {
            ListNode* h = prevG;
            
            int c = k;
            while(h && c)
            {
                c--;
                h = h->next;
            }
            if(h == NULL)
                break;
            
            ListNode* nxtG = h->next;

            ListNode* prev = h->next;
            ListNode* cur = prevG->next;
            ListNode* nxt;
            while(cur != nxtG)
            {
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }

            ListNode* tmp = prevG->next;
            prevG->next = h;
            prevG = tmp;
        }
        return dummy->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseNodes(head,k);
    }
};
