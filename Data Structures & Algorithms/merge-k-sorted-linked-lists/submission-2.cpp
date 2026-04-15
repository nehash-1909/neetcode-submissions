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
        if(lists.empty())
            return NULL;

        int n = lists.size();
        //ListNode* dummy = new ListNode(0, NULL);
        //ListNode* temp = dummy;

        for(int i=1;i<n;i++)
        {
            lists[i] = merge2Lists(lists[i], lists[i-1]);
            //dummy->next = temp;
        }
        return lists[n-1];
    }
};
