class Solution {
public:
    unordered_map<char,int> seq;
    bool cmp(string w1, string w2)
    {
        int n = w1.size();
        int m = w2.size();
        for(int i=0;i<min(n,m);i++)
        {
            if(w1[i] != w2[i])
            {
                return seq[w1[i]] < seq[w2[i]];  
            }
        }

        // all chars same → shorter word should come first
        return n <= m;
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        int i=1;
        for(auto c: order)
        {
            seq[c] = i++;
        }

        for(int i=0;i<words.size()-1;i++)
        {
            if(cmp(words[i],words[i+1]) == false)
                return false;
        }
        return true;
    }
};