class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        // vector<int> v(26, 0);
        // vector<int> res;
        
        // for(auto c:s)
        // {
        //     v[c-'a']++;
        // }
        // string ans = "";
        // for(auto c:s)
        // {
        //     ans += c;
        //     v[c-'a']--;

        //     bool flag = true;
        //     for(auto i:ans)
        //     {
        //         if(v[i-'a'] != 0)
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }

        //     if(flag == true)
        //     {
        //         //correct word
        //         res.push_back(ans.size());
        //         ans = "";
        //     }
        // }
        // return res;

        vector<int> v(26, 0);
        vector<int> res;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'] = i;
        }
        int end = 0;
        int start = 0;
        for(int i=0;i<n;i++)
        {
            end = max(end, v[s[i]-'a']);

            if( i == end)
            {
                res.push_back(end-start+1);
                start = i+1;
            }
        }

        return res;
    }
    
};
