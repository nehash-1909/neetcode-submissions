class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {

        int n = nums.size();

        int total = (n*(n+1))/2;
        int res = 0;
        for(auto i:nums)
        {
            res += i;
        }
        return total-res;
    }
};
