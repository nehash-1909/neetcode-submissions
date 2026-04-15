class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // 0 1 2 3 4
        // 1 2 3 2 2
        //
        int ans = -1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int temp = abs(nums[i]);
            if(nums[temp-1] < 0)
                return temp;
            nums[temp-1] = -nums[temp-1];
        }
        // 0 1 2 3 4
        // 3 1 3 4 2
        //       

        return ans;
        
    }
};
