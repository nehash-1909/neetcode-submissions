class Solution {
public:
    bool validPalindrome(string s) 
    {

        int l = 0;
        int r = s.size()-1;
        bool flag = false;
        while(l<=r)
        {
            if(s[l] != s[r])
            {
                // check l+1 --> r is palindrom, i.e., l is not included
                // or    l.  --> r-l is palindromi.e., r is not included
                return isPalindrome(s, l + 1, r) ||
                       isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }

        return true;
        
    }

     bool isPalindrome(const string& s, int l, int r) 
    {

        while(l<=r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
        
    }
};