class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> pref(n,1);
        vector<int> suf(n,1);

        vector<int> res(n,1);
        pref[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            pref[i] = pref[i-1]*nums[i];
            //cout<<i<<" "<<pref[i]<<endl;
        }
        //cout<<endl;
        for(int i=n-2;i>=0;i--)
        {
            suf[i] = suf[i+1]*nums[i];
            //cout<<suf[i]<<" ";
        }

        
        
        for(int i=1;i<n-1;i++)
        {
            res[i] = pref[i-1]*suf[i+1];
        }
        //cout<<"pref "<<pref[n-1]<<endl;
        res[0] = suf[1];
        res[n-1] = pref[n-2];

        return res;

    }
};
