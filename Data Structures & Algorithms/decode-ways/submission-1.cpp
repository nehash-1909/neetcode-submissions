class Solution {
public:
int getVal(string s, int start) 
    {
        cout<<s<<endl;
        if(s[start] == '0')
            return 0;
        if(s.size() <= 2)
        {
            int num = stoi(s);
            if(num <= 10 || num<=26)
                return 1;
        }
        return getVal(s.substr(start+1, s.size()),start+1);
    }
    int numDecodings(string s) 
    {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;
        int dp[n] = {0};
        dp[0] = 1;

        for(int i=1;i<n;i++)
        {
            if(s[i] != '0')
                dp[i] = dp[i-1];
            int num = (s[i-1] - '0') * 10 + (s[i] - '0');
            if(num>=10 && num<=26)
            {
                if(i>=2)
                    dp[i] += dp[i-2];
                else
                    dp[i] += 1;
            }
        }
        return dp[n-1];
    }
};


