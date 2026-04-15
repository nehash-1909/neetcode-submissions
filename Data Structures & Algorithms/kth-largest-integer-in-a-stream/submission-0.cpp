class KthLargest {
private:
    
public:
    //priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int g;
    
    KthLargest(int k, vector<int>& nums) {
        g = k;

        for(auto i:nums)
        {
            minHeap.push(i);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
    }
    
    int add(int val) {

        minHeap.push(val);
        if(minHeap.size() > g)
                minHeap.pop();

        return minHeap.top();
        
    }
};
