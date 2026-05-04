class MyHashMap {
private:
    struct ListNode 
    {
        int key, val;
        ListNode* next;

        // ListNode(int key = -1, int val = -1, ListNode* next = nullptr)
        // {
        //     key = key;
        //     val = val; 
        //     next = next;
        // }

        ListNode(int key = -1, int val = -1, ListNode* next = nullptr)
            : key(key), val(val), next(next) {}
    };

    vector<ListNode*> map;
    int hash(int key) 
    {
        return key % map.size();
    }
public:
    MyHashMap()
    {
        map.resize(1000);
        for (auto& bucket : map) 
        {
            bucket = new ListNode(0);
        }
    }
    
    void put(int key, int value) 
    {
        ListNode* bucket = map[hash(key)];
        while(bucket->next != NULL)
        {
            if(bucket->next->key == key)
            {
                bucket->next->val = value;
                return;
            }
            bucket = bucket->next;
        }
        bucket->next = new ListNode(key, value, NULL);
    }
    
    int get(int key) {
        ListNode* bucket = map[hash(key)]->next;
        while(bucket != NULL)
        {
            if(bucket->key == key)
            {
                return bucket->val;
            }
            bucket = bucket->next;
        }

        return -1;

        
    }
    
    void remove(int key) 
    {
        ListNode* bucket = map[hash(key)];
        while(bucket->next != NULL)
        {
            if(bucket->next->key == key)
            {
                ListNode* tmp = bucket->next;
                bucket->next = bucket->next->next;
                delete tmp;
                return;
            }
            bucket = bucket->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */