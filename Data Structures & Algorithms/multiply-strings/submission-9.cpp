class Solution {
public:
    string multiply(string num1, string num2) 
    {

        int n = num1.size()-1;
        int m = num2.size()-1;

        //cout<<n<<" "<<m<<endl;

        vector<int> res(n + m+2, 0);

        for(int i=m;i>=0;i--)
        {
            for(int j=n;j>=0;j--)
            {
                long long mul = (num2[i] - '0')*(num1[j] - '0');
                long long sum = mul + res[i+j+1] ;
                res[i+j+1] =  sum%10;
                res[i+j] += sum/10;
            }
        }
        string ans = "";
        for(auto val:res)
        {
            if (!(ans.empty() && val == 0))
                ans += to_string(val);
        }
        if(ans.empty())
            return "0";
        return ans;
    }
};
