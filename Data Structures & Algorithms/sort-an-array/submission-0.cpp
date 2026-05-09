class Solution {
public:
    int getpivot(vector<int>& nums, int s, int e)
    {
        // 1 9 2 4 3 4

        int pivot = nums[e];
        int i = s-1;

        for(int j=s;j<=e;j++)
        {
            if(nums[j] < pivot)
            {
                // j is always increasing but i only get increase
                // value is less than pivot
                i++;
                //nums[i] --> element greater than pivot
                // swap it with element less than 
                swap(nums[i], nums[j]);
            }
            // if this element is bigger than pivot we will 

        }

        // move pivot after smaller elements and
        // return its position
        swap(nums[i + 1], nums[e]);  
        return i+1;
    }
    void qsort(vector<int>& nums, int s, int e)
    {
        if(s >= e)
            return;
        int m = getpivot(nums, s,e);
        qsort(nums, s, m-1);
        qsort(nums, m+1, e);
    }
    vector<int> sortArray(vector<int>& nums) 
    {

        qsort(nums,0,nums.size()-1);
        return nums;
        
    }
};