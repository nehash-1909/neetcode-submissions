class Solution {
public:
    string foreignDictionary(vector<string>& words) 
    {
        int n = words.size();
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> degree;
        set<char> all_char;

        // collect all characters
        for(auto &word : words)
            for(char c : word)
                all_char.insert(c);

        for(char c : all_char)
            degree[c] = 0;

        string ans = "";

        /*
        The dictionary is already sorted lexicographically, so:
        Only adjacent words give valid ordering constraints.
        */
        for(int i = 0;i<n-1;i++)
        {
            int j = i+1;
            int w1_len = words[i].size();
            int w2_len = words[j].size();

            int len = min(w1_len, w2_len);
            bool isPrefix = true;

            for(int k=0;k<len;k++)
            {
                if(words[i][k] != words[j][k])
                {
                    if(!adj[words[i][k]].contains(words[j][k]))
                    {
                        adj[words[i][k]].insert(words[j][k]);
                        degree[words[j][k]]++;
                    }
                    isPrefix = false;
                    break;
                }
            }

            if(isPrefix && w1_len>w2_len)
                return "";
        }

        queue<char> q;

        for(auto &c:all_char)
        {
            if(degree[c] == 0)
                q.push(c);
        }

        while(!q.empty())
        {
            char node = q.front();
            q.pop();
            ans += node;
            for(auto &nei:adj[node])
            {
                degree[nei]--;
                if(degree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        // cycle check
        if(ans.size() != all_char.size())
            return "";
        return ans;
    }
};
