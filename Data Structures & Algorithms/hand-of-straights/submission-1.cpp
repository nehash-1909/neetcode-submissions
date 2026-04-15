class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {

        int n = hand.size();
        unordered_map<int,int> hash;
        priority_queue<int, vector<int>, greater<int>> minHeap;


        for(auto h:hand)
        {
            hash[h]++;
            //minHeap.push(h);
        }

        for(auto &h:hash)
        {
            //hash[h]++;
            minHeap.push(h.first);
        }

        while(!minHeap.empty())
        {
            int minVal = minHeap.top();


            for(int i=minVal;i<minVal+groupSize;i++)
            {
                if(!hash.contains(i))
                {
                    return false;
                }
                hash[i]--;
                if(hash[i] == 0)
                {
                    if(i != minHeap.top())
                        return false;
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};
