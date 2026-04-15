class Solution {
public:
    bool checkValid(unordered_map<char,int> arr1, unordered_map<char,int> arr2)
    {

        for(auto &c: arr1)
        {
            if(arr1[c.first] > arr2[c.first])
                return false;
        }

        return true;

    }
    string minWindow(string s, string t) {

        unordered_map<char,int> arr1;
        unordered_map<char,int> arr2;

        if(s.size() < t.size())
            return "";
        for(int i = 0;i<t.size();i++)
        {
            arr1[t[i]]++;
            arr2[s[i]]++;
        }

        int l = 0;
        int r = t.size();
        int maxS = 0;
        string ans = "";
        //OUZODYXAZV
        //XYZ
        while(r<s.size()|| checkValid(arr1,arr2))
        {
            
            if(checkValid(arr1, arr2))
            {
                
                if(ans == "" || (r-l) < maxS)
                {
                    ans = s.substr(l, (r-l));
                    maxS = r-l;
                }
                arr2[s[l]]--;
                l++;
            }
            else
            {
                //cout<<s[l]<<" "<<arr2[s[l]]<<" "<<s[r]<<" "<<arr1[s[r]]<<endl;
                arr2[s[r]]++;
                r++;
            }

        }
        return ans;  
    }
};
