class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {

        // one side would be sorted other size would be 
        // rotated
        // 0 1 2 3 4 5
        // 3 4 5 6 1 2
        // mid : 3
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l<=r)
        {
            int m = (l+r)/2;
            /*left side of the array */
            if(nums[m] == target)
                return true;
            if(nums[l] < nums[m])
            {
                // sorted size
                if(nums[l] <= target && target<nums[m])
                {
                    // target exist here
                    r = m-1;
                }
                else 
                {
                    l = m+1;
                }
                
            }
            else if(nums[l] > nums[m])
            {
                /*right side of the array */
                if(nums[r] >= target && target>nums[m])
                {
                    // target exist here
                    l = m+1;
                }
                else
                {
                    r = m-1;
                }

            }
            else
                l++;
        }

        return false;
        
    }
};