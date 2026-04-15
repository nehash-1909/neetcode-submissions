class Solution {
public:
    bool isAnagram(string s, string t) {


        int arr[26] = {0};

        for(auto i:s)
        {
            arr[i-97]++;
            //printf("%d and %c \n", i-97, i);
        }

        for(auto i:t)
        {
            arr[i-97]--;
        }

        for(auto i:arr)
        {
            if(i != 0)
                return false;
        }

        return true;
        
    }
};
