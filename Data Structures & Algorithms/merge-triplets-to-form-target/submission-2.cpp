class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target)
    {
        int n = triplets.size();
        vector<int> ans(3,0);
        for(int j=0;j<n;j++)
        {
            if(triplets[j][0] > target[0] || triplets[j][1] > target[1] || triplets[j][2] > target[2])
                continue;
            
            for(int i=0;i<3;i++)
            {
                if(triplets[j][i] == target[i])
                {
                    ans[i] = target[i];
                }
                //cout<<triplets[i][j]<<" "<<ans[j]<<endl;
            }
            //cout<<"********"<<endl;
        }

        for(int j=0; j<3; j++)
        {
            //cout<<target[j]<<" "<<ans[j]<<endl;
            if(ans[j] != target[j])
                return false;
        }    
        return true;
    }
};
