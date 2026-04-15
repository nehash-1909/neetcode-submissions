class Solution {
public:
    bool checkArr(int arr1[], int arr2[])
    {
        for(int i=0;i<26;i++)
        {
            //cout<<arr1[i]<<" "<<arr2[i]<<endl;
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        if(s2.size() < s1.size())
            return false;
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(auto s:s1)
        {
            arr1[s-'a']++;
        }

        int n = s1.size();
        int l = 0;
        int r = 0;
        for(r=0;r<n;r++)
        {
            arr2[s2[r]-'a']++;
            if(checkArr(arr1, arr2) == true)
                return true;
        }

        for(r=n;r<s2.size();r++)
        {
            arr2[s2[l]-'a']--;
            arr2[s2[r]-'a']++;

            //cout<<s2[l]<<" "<<s2[l]-'a'<<" "<<s2[r]<<" "<<s2[r]-'a'<<endl;
            if(checkArr(arr1, arr2) == true)
                return true;

            l++;
            //r++;
        }

        return false;

        

        
    }
};
