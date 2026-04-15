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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1->2-3
        // 3 9 2 ==> 293
        // 9 8   ==>. 89
        //             12/1
        ListNode* dummy = new ListNode(0,NULL);
        ListNode* head = dummy;
        int rem = 0;

        while(l1 && l2)
        {
            int sum = (l1->val + l2->val + rem);
            rem = (sum>=10)? 1: 0;
            int val = sum%10;
            //cout<<val<<" "<<rem<<endl;
            l1 = l1->next;
            l2 = l2->next;
            ListNode* temp = new ListNode(val, NULL);
            head->next = temp;
            head = head->next;
        }
        // 9 9 9 9 9 9 9
        // 9 9 9 9
        // 8 9 9 9 0 0 
        while(l1)
        {
            int sum = (l1->val + rem);
            rem = (sum>=10)? 1: 0;
            int val = sum%10;
            //cout<<val<<" "<<rem<<endl;
            l1 = l1->next;
            ListNode* temp = new ListNode(val, NULL);
            head->next = temp;
            head = head->next;
        }
        
        while(l2)
        {
            int sum = (l2->val + rem);
            rem = (sum>=10)? 1: 0;
            int val = sum%10;
            //cout<<val<<" "<<rem<<endl;
            l2 = l2->next;
            ListNode* temp = new ListNode(val, NULL);
            head->next = temp;
            head = head->next;
        }
        
        if(rem)
        {
            ListNode* temp = new ListNode(1, NULL);
            head->next = temp;
        }
        

        return dummy->next;
        
    }
};
