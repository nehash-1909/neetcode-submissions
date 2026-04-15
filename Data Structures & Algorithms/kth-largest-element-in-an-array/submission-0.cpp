class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto i:nums)
        {
            minHeap.push(i);
            //cout<<"pushed "<<i<<endl;
            if(minHeap.size()>k)
            {
                //cout<<"poped "<<minHeap.top()<<endl;
                minHeap.pop();
            }
        }

        return minHeap.top();
        
    }
};
