class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l=0, r=nums.size()-1;
        for(int i=0;i<nums.size(); i++)
        {
            while(i<=nums.size()-1 && i>0 && nums[i] == nums[i-1])
                    i++;
            int target = -nums[i];
            l = i+1;
            r = nums.size()-1;
            while(l<r)
            {
              //cout<<nums[l]<<" "<<nums[r]<<" "<<target<<endl;

              
               if(nums[l]+nums[r] > target)
                    r--;
                else if(nums[l]+ nums[r] < target)
                    l++;
                else
                {
                    vector<int> temp_res(3,0);
                    temp_res[0] = -target;
                    temp_res[1] = nums[l];
                    temp_res[2] = nums[r];

                    res.push_back(temp_res);
                    r--;
                    l++;
                
                while(l<r && l>0 && nums[l] == nums[l-1])
                    l++;
                }
            }
                
        }
        return res;
        
    }
};
