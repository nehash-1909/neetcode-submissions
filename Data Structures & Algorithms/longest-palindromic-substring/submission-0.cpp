class Solution {
public:
    bool isPalindrome(string s)
    {   
        int l = 0;
        int r = s.size()-1;
        while(l<=r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
    string longestPalindrome(string s) {

        int start = 0;
        int end = 0;
        int n = s.size();
        for(int l = 0; l < n; l++) 
        {
            for(int r = l; r < n; r++) 
            {
            //cout<<l<<" "<<r<<endl;
                if(isPalindrome(s.substr(l, r-l+1)))
                {

                    if(end-start < r-l)
                    {
                        start = l;
                        end = r;
                    }
                }
            }
        }
        string ans = s.substr(start, end-start+1);
        return ans;
    }
};
