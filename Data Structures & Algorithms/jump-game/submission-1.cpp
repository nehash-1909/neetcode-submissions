class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 0 1 2 3 4
        // 1 2 0 1 0
        //       2

        // 1 2

        int n = nums.size();
        int maxReachInd = 0;
        for(int i=0;i<n;i++)
        {
            if(i > maxReachInd)
                return false;
            maxReachInd = max(maxReachInd, nums[i] + i);
        }
        return true;
    }
};
