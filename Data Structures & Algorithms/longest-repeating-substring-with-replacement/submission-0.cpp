class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int arr[26] = {0};
        int l = 0;
        int r = 0;
        int maxVal = 0;
        int maxLen = 0;
    
        // XYYX
        while(r < s.size())
        {
            
            arr[s[r]-'A']++;

            maxVal = max(maxVal, arr[s[r]-'A']);

            if((r-l+1)-maxVal > k)
            {
                arr[s[l]-'A']--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;

        }

        return maxLen;
    }
};
