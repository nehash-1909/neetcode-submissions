class Solution {
public:
    int getMaxVal(vector<int>& nums)
    {
        int maxVal = 0;
        for(int i = 0;i<nums.size();i++)
        {
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        priority_queue<pair<int,int>> qp;
        int i=0;
        while(i<k)
        {
            qp.push({nums[i],i});
            //res.push_back(qp.top().first);
            i++;
        }
        res.push_back(qp.top().first);
        for(int i=k;i<nums.size();i++)
        {
            qp.push({nums[i],i});
            while(qp.top().second <= i-k)
            {
                qp.pop();
            }
            
            res.push_back(qp.top().first);
        }

        return res;
        
    }
};
