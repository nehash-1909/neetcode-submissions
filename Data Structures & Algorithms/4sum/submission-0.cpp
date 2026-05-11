class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0;i<n-3;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int first = nums[i];
            for(int j=i+1;j<n-2;j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                int second = nums[j];

                int l = j+1;
                int r = n-1;

                while(l<r)
                {
                    long long sum = 1LL * first + second + nums[l] + nums[r];

                    if(sum == target)
                    {
                        res.push_back({first,second, nums[l] , nums[r]});
                        r--;
                        l++;
                        while(l < r && nums[l] == nums[l-1])
                            l++;

                        while(l < r && nums[r] == nums[r+1])
                            r--;
                    }
                    else if(sum > target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }

                }

            
            }   
        }

        return res;
        
    }
};