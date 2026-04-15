class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {

        // int n = nums.size();

        // int total = (n*(n+1))/2;
        // int res = 0;
        // for(auto i:nums)
        // {
        //     res += i;
        // }
        // return total-res;

        // 2 ^ 2 = 0

        int res = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            // n = 3 => 0 1 2
            // nums contains => 1 2 3
            // xor of both => 1 ^ 3(n number would be always there)
            res ^= (i^nums[i]);
        }
        return res;

    }
};
