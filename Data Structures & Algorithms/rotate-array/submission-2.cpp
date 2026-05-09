class Solution {
public:
    void swapList(vector<int>& nums, int l, int r)
    {
        while(l<=r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

    } 
    void rotate(vector<int>& nums, int k) 
    {

        int n =nums.size();
        k %=n;

        swapList(nums, 0, n-1);
        swapList(nums, 0, k-1);
        swapList(nums, k, n-1);
        
    }
};