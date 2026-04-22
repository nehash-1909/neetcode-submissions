class Solution {
public:
    //unordered_map<char,int> m;
    string encode(vector<string>& strs) {
            string s = "";
            for(auto v:strs)
            {
                
                for(auto c: v)
                    s += ((c+26)%256);
                s += "#";
            }
        cout<<"encode: "<<s<<endl;
        return s;


    }

    vector<string> decode(string s) {
        vector<string> res;
        string ans = "";
        for(auto c:s)
        {
             
            if(c == '#')
            {
                //cout<<"decode: "<<ans<<" ";
                res.push_back(ans);
                ans = "";
                continue;
            }
            //cout<<(c - 26 + 256) % 256<<" ";
            ans += (c - 26 + 256) % 256;
            
        }
        return res;

    }
};
