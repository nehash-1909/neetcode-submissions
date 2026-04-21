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
        Node* h = head;
        Node* temp = NULL;
        Node* dummy = new Node(0);
        unordered_map<Node*, Node*> hash;
        int i = 0;
        while(head)
        {
            Node* t = new Node(head->val);
            t->next = NULL;
            t->random = NULL;

            hash[head] = t;
            ///i++;
            
            if(dummy->next)
            {
                temp->next = t;
                temp = temp->next;
            }
            else
            {
                temp = t;
                dummy->next = temp;
            }

            head = head->next;
            
        }
        temp = dummy->next;
        while(h)
        {
            if(h->random)
            {
                //cout<<h->random->val<<" ";
                temp->random = hash[h->random];
            }
            else
                temp->random = NULL;
            
            h = h->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};