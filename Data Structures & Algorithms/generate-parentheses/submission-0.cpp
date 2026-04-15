class Solution {
public:
    void generate(vector<string> &res, string &ans, int n, int open, int close)
    {
        if(ans.size() == 2*n)
        {
            res.push_back(ans);
            return;
        }

        if(open < n)
        {
            ans += '(';
            generate(res, ans,n, open+1, close);
            ans.pop_back();
        }
        if(close < open)
        {
            ans += ')';
            generate(res, ans,n,open, close+1);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string ans = "";
        generate(res, ans,n, 0, 0);
        return res;
    }
};
