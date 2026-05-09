class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {

        // 1 2 3 4 5 6 7 8 k = 2
        // 8 7 1 2 3 4 5 6
        // 1 2 3 4 5 6 8 7
        // 8 7 6 5 4 3 2 1
        // 8 7 1 2 3 4 5 6
        // 8 7 6 5 4 3 2 1
        // 1 2 3 4 5
        // 4 5 1 2 3
        // 5 4 3 2 1
        int n =nums.size();

        int l = 0;
        int r = n-1;
        k %=n;
        while(l<=r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        l = k;
        r = n-1;
        while(l<=r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        l = 0;
        r = k-1;
        while(l<=r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }




        
    }
};