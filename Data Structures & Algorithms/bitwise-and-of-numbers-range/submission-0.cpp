class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        // 1 0 1 0
        // 1 0 1 1
        // 1 1 0 0 
        //       1

        int ans = left;
        for(int i=left+1;i<=right;i++)
        {
            ans &= i;
        }

        return ans;
        
    }
};