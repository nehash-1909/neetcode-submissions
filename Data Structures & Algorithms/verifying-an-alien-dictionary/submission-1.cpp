class Solution {
public:
    int seq[26] = {0};
    bool cmp(string w1, string w2)
    {
        int n = w1.size();
        int m = w2.size();
        for(int i=0;i<min(n,m);i++)
        {
            if(w1[i] != w2[i])
            {
                return seq[w1[i]-'a'] < seq[w2[i]-'a'];  
            }
        }

        // all chars same → shorter word should come first
        return n <= m;
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {

        for (int i = 0; i < order.size(); ++i)
        {
            seq[order[i]-'a'] = i;
        }

        for(int i=0;i<words.size()-1;i++)
        {
            if(cmp(words[i],words[i+1]) == false)
                return false;
        }
        return true;
    }
};