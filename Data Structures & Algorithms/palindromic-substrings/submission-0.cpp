class Solution {
public:
    int countPal(string s, int l, int r)
    {
        int res = 0;
        while(l >= 0 && r<s.size() && s[l] == s[r])
        {
            res++;
            l--;
            r++;
        }

        return res;
    }
    int countSubstrings(string s) 
    {
        
        int res = 0;

        for(int i=0;i<s.size();i++)
        {
            res += countPal(s, i,i);
            res += countPal(s, i,i+1);
        }
        return res;
    }
};
