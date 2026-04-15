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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0, NULL);
        ListNode* temp = dummy;

        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                temp->next = list2;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }

        if(list1)
        {
            temp->next = list1;
        }

        if(list2)
        {
            temp->next = list2;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {

        int n = lists.size();
        ListNode* dummy = new ListNode(0, NULL);
        ListNode* temp = dummy;

        for(int i=0;i<n;i++)
        {
            temp = merge2Lists(lists[i], dummy->next);
            dummy->next = temp;
        }
        return dummy->next;
    }
};
