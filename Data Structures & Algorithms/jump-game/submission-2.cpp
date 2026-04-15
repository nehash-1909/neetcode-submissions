class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // maximum reachable index
        // int maxReachInd = 0;
        // for(int i=0;i<n;i++)
        // {
        //     if(i > maxReachInd)
        //         return false;
        //     maxReachInd = max(maxReachInd, nums[i] + i);
        // }
        // return true;

        // 0  1  2    3  4
        // 1  2  0    1  0
        // 1  1  -2  -2 -4
        int goal = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] + i >= goal)
            {
                goal = i;
            }
        }
        return (goal==0);
    }
};
