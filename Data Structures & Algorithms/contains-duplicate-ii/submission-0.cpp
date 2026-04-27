class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {

        unordered_map<int,int> hash;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(hash.contains(nums[i]))
            {
                if(abs(i-hash[nums[i]]) <= k)
                {
                    //cout<<i<<" "
                    return true;
                }
            }
            
            hash[nums[i]] = i;
        }

        return false;
        
    }
};