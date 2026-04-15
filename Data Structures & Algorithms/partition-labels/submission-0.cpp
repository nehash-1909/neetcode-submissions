class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> v(26, 0);
        vector<int> res;
        
        for(auto c:s)
        {
            v[c-'a']++;
            //cout<<c<<" "<<v[c-'a']<<endl;
        }
        string ans = "";
        for(auto c:s)
        {
            ans += c;
            v[c-'a']--;

            bool flag = true;
            //cout<<endl<<"string"<<" ";
            for(auto i:ans)
            {
                //cout<<i<<" ";
                if(v[i-'a'] != 0)
                {
                    //cout<<v[i]<<" ";
                    flag = false;
                    break;
                }
            }

            if(flag == true)
            {
                //correct word
                res.push_back(ans.size());
                ans = "";

            }
        }
        return res;
    }
    
};
