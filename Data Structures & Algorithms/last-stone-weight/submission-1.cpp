class Solution {
public:
    priority_queue<int> maxHeap;
    int lastStoneWeight(vector<int>& stones) {
        for(auto s:stones)
        {
            maxHeap.push(s);
        }

        while(maxHeap.size()>=2)
        {
            int s1 = maxHeap.top();
            maxHeap.pop();
            int s2 = maxHeap.top();
            maxHeap.pop();

            int s3 = abs(s1-s2);
            maxHeap.push(s3);

        }

        return maxHeap.top();
    }
};
