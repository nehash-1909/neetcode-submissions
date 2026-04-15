class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxReached = 0;
        int maxjump = 0;
        for(int i=0;i<n-1;i++)
        {
            // maximum i could jump from ith index
            maxjump = max(maxjump, nums[i]+i);

            // once i reached maximum jump for last i, now set next jump 
            if(i == maxReached)
            {
                maxReached = maxjump;
                count++;
            }
        }
        return count;
        
    }
};
