class Solution {
public:
    #if 0
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
    #endif
    int findDuplicate(vector<int>& nums) 
    {
        int slow = 0;
        int fast = 0;
        int ans = -1;
        int n = nums.size();
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }

        slow = 0;

        while(1)
        {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast)
                return slow;
        }
    }
};
