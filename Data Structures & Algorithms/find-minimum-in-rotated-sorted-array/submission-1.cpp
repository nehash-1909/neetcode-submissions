class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int target = nums[0];
        while(l<=r)
        {
            // if final sorted array
            if(nums[l] < nums[r])
            {
                target = min(target,nums[l]);
                break;
            }
            int m = (l+r)/2;
            target = min(target,nums[m]);
            // one part is always sorted, and 
            // the other part contains the rotation (and the minimum element).
            if(nums[l] <= nums[m])
            {
                //left sorted so other part has value
                l = m+1;

            }
            else
            {
                r = m-1;
            }

            
        }
        return target;        
    }
};
