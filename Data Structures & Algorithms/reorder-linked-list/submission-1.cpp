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
 // 1 2 3 4 5 6 7
 // 0 1 2 3 4 5 6
 //

class Solution {
public:
    ListNode* getMiddleList(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode* reverList(ListNode* head)
    {
        // 2->4->6->8->10
        // 2>NULL 4->6->8->10
        //prev =NULL, cur = 4
        // nxt = 6
        // 4->NULL
        // prev = 4
        //cur = 6
        //

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nxt;

        while(cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;

    }
    void reorderList(ListNode* head) {

        if(!head || !head->next) return; 

        ListNode dummy(0);
        ListNode* h = &dummy;

        ListNode* prevM = getMiddleList(head);
        ListNode* newhead = reverList(prevM->next);
        prevM->next = NULL;
        //cout<<newhead->val<<endl;
        #if 0
        while(head)
        {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
        #endif
        while(head && newhead)
        {
            //cout<<newhead->val<<" ";
            //newhead = newhead->next;
            //#if 0
            h->next = head;
            head = head->next;
            h = h->next;
            h->next = newhead;
            newhead = newhead->next;
            h = h->next;
            //#endif
        }
        //cout<<endl;
        if(head)
            h->next = head;

        head = dummy.next;
    }
};
