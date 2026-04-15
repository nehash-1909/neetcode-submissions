class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> res;
        for(int idx=0;idx<=n;idx++)
        {
            int c = 0;
            int i = idx;
            while(i)
            {
                if(i&1)
                    c++;
                i = i>>1;
            }
            res.push_back(c);

        }
        return res;
    }
};
