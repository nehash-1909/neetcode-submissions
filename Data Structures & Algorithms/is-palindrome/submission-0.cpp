class Solution {
public:
    bool Isalphanum(char c)
    {
        if((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            //cout<<"returning true "<<c<<" "<<endl;
            return true;
        }
        //cout<<"returning false"<<endl;
        return false;
    }
public:
    bool isPalindrome(string s) {

        int r = s.length()-1;
        int l = 0;

        while(l<r)
        {
            //cout<<s[l]<<" "<<s[r]<<endl;
            while(l<r && Isalphanum(s[l]) != true)
                l++;
            while(l<r && Isalphanum(s[r]) != true)
                r--;
            if(l<r && ((char)tolower(s[l]) != (char)tolower(s[r])))
                return false;
            l++;
            r--;
        }

        return true;

        
    }
};