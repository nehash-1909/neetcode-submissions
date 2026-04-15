class Solution {
public:
    bool isPalindrome(string ans)
    {
        int n = ans.size();
        int l = 0;
        int r = n-1;
        if(n <= 0)
            return false;
        if(n==1)
            return true;
        while(l <= r)
        {
            if(ans[l] != ans[r])
                return false;
            
            l++;
            r--;
        }

        return true;
    }
    void palindromePart(string s, vector<vector<string>> &res, vector<string> &ans, string &temp, int idx)
    {
        if(idx == s.size()+1)
        {
            res.push_back(ans);
            return;
        }

        for(int i = idx;i<=s.size();i++)
        {
            temp = s.substr(idx, i-idx+1);
            //cout<<"idx "<<idx<<" "<<i<<endl;
            if(isPalindrome(temp))
            {
                //cout<<temp<<endl;
                ans.push_back(temp);
                palindromePart(s, res,ans, temp, i+1);
                ans.pop_back();
                //palindromePart(s, res,ans, temp, i+1);
            }
        }

        // temp += s[idx];
        // ans.push_back(temp);
        // if(isPalindrome(temp))
        // {
        //     palindromePart(s, res,ans, temp, idx+1);
        // }
        // ans.pop_back();
        // temp.pop_back();
        // palindromePart(s, res,ans, temp, idx+1);
        
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> ans;
        string temp = "";
        palindromePart(s, res,ans, temp, 0);
        return res;
    }
};
