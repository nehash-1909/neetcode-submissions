class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string ans = "";
        while(columnNumber)
        {
            int idx = (columnNumber-1)%26;
            columnNumber = (columnNumber-1)/26;
            ans += ('A'+idx);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        

    }
};