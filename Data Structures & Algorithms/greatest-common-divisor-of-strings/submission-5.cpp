#include <cstring>
class Solution {
public:
    bool gcd(int l, string &ans, string &str1, string &str2)
    {
        int n = str1.size();
        int m = str2.size(); 

        if(l == 0 || n % l || m % l)
            return false;

        string s1 = "";
        for(int i = 0; i < n / l; i++)
            s1 += ans;

        string s2 = "";
        for(int i = 0; i < m / l; i++)
            s2 += ans;

        return (s1 == str1 && s2 == str2);
    }
    string gcdOfStrings(string str1, string str2) 
    {
        int n = str1.size();
        string s = "";
        // longest string needed
        for(int i=n;i>0;i--)
        {
            // get substring and check if its matching
            string ans = str1.substr(0, i);
            if(gcd(i, ans,str1,str2))
                return ans;
        }
        return "";
    }
};