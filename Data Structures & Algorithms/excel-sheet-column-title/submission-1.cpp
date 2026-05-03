class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        char mp[30];

        for(int i=0;i<26;i++)
        {
            mp[i] = 'A'+i;
            
        }
        /* 53 = */
        string ans = "";
        while(columnNumber)
        {
            int idx = (columnNumber-1)%26;
            //cout<<idx<<" "<<mp[idx]<<endl;
            columnNumber = (columnNumber-1)/26;

            ans += mp[idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
        

    }
};