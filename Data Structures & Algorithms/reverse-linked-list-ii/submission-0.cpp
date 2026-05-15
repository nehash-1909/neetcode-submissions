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
    ListNode* reverse(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nxtCur;
        while(cur)
        {
            nxtCur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxtCur;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* sublistHead = prev->next;
        ListNode* sublistTail = sublistHead;
        for (int i = 0; i < right - left; ++i) {
            sublistTail = sublistTail->next;
        }

        ListNode* nextNode = sublistTail->next;
        sublistTail->next = nullptr;
        prev->next = reverse(sublistHead);
        sublistHead->next = nextNode;

        return dummy.next;

        
    }
};