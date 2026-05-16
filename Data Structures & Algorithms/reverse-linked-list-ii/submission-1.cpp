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
    ListNode* reverseList(ListNode* head) 
    {

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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevList = &dummy;

        ListNode* subListHead;
        ListNode* subListTail;

        for(int i=1;i<left;i++)
        {
            prevList = prevList->next;
        }
        subListHead = prevList->next;
        subListTail = subListHead;
        for(int i=left;i<right;i++)
        {
            subListTail = subListTail->next;
        }
        ListNode* nxt = subListTail->next;
        subListTail->next = NULL;

        /*
             1 -> 2 -> 3 -> 4->5
             left = 2, right = 4

             1->2->3->4->NULL->
             5


        */

        //first element is prevList->next
        //last element is
        prevList->next = reverseList(subListHead);
        subListHead->next = nxt;

        return dummy.next;

        
    }
};