class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char,int> hash;
        while(r<s.size())
        {
            if(hash.contains(s[r]) == true)
            {
                //hash[s[r]] = r;
                l = max(l, hash[s[r]]+1);
            }

            hash[s[r]] = r;
            //cout<<s[l]<<" "<<s[r]<<" "<<l<<" "<<r<<endl;
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
        
    }
};
