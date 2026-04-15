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

 // 0 -> 1<--2 <-- 3 <-- 4 <-- 5
 // new_head = head;
 // new_head -> next = head;
 // return head;


class Solution {
    ListNode* head_reverse;
public:
    ListNode* reverseL(ListNode* head){
        if(head->next == NULL)
        {
            cout<<head->val<<endl;
            head_reverse = head;
            return head;
        }
        
        ListNode* new_head = reverseL(head->next);
        new_head->next = head;
        head->next = NULL;
        cout<<head->val<<endl;
        return head;

    }
    ListNode* reverseList(ListNode* head) {

        if(head == NULL)
            return head;
        reverseL(head);
        return head_reverse;
        
    }
};
