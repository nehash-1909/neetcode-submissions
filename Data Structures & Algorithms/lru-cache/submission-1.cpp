/*

*/
class LRUCache {
public:
    typedef struct Node
    {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
    }Node;
    
    int size;
    int curSize = 0;
    Node* cache = NULL;

    LRUCache(int capacity) 
    {
        size = capacity;
        cache = NULL;
    }
    void moveToTail(Node* temp)
    {
        if (!temp || !temp->next) return; // already tail

        // detach node
        if(temp->prev)
            temp->prev->next = temp->next;
        else
            cache = temp->next;
        if(temp->next)
            temp->next->prev = temp->prev;


        Node* tail_node = cache;
        while(tail_node->next)
        {
            tail_node = tail_node->next;
        }
        
        tail_node->next = temp;
        temp->prev = tail_node;
        temp->next = NULL;
    }
    
    int get(int key) 
    {
        if(cache == NULL)
            return -1;
        
        Node* temp = cache;

        while(temp)
        {
            if(temp->key == key)
            {
                int val = temp->val;
                moveToTail(temp);
                return val;
            }
            temp = temp->next;
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        if(cache == NULL)
        {
            cache = new Node(key, value);
            curSize = 1;
            return;
        }
        Node* temp =cache;
        while(temp)
        {
            if(temp->key == key)
            {
                temp->val = value;
                moveToTail(temp);
                return;
            }
            temp = temp->next;
        }

        if(curSize == size)
        {
            Node* del_node = cache;
            cache = cache->next;
            if(cache)
                cache->prev = NULL;

            delete del_node;
            curSize--;

            if(cache == NULL)
            {
                cache = new Node(key, value);
                curSize = 1;
                return;
            }

        }
        temp = cache;
        while(temp->next)
        {
            temp = temp->next;
        }
        Node* newNode = new Node(key, value);
        
        temp->next = newNode;
        newNode->prev = temp;
        curSize++;
        return;
    }
};
