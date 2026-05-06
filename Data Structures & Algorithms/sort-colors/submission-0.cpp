class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(auto i:nums)
        {
            if(i == 0)
                count0++;
            else if(i == 1)
                count1++;
            else
                count2++;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i<count0)
                nums[i] = 0;
            else if(i<count1+count0)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};