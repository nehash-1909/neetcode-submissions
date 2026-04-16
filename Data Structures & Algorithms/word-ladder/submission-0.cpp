class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {

        if(beginWord == endWord)
            return 0;

        int n = wordList.size();
        unordered_set<string> s(wordList.begin(), wordList.end());

        if(s.count(endWord) == 0)
            return 0;

        queue<string> q;
        q.push(beginWord);

        int res = 0;
        while(!q.empty())
        {
            res++;
            int len = q.size();

            for(int j=0;j<len;j++)
            {
                string word = q.front();
                q.pop();

                if(word == endWord)
                    return res;

                int wordSize = word.size();

                for(int i=0;i<wordSize;i++)
                {
                    char og = word[i];
                    for(char c='a';c<='z';c++)
                    {
                        if(og == c)
                            continue;
                        word[i] = c;
                        if(s.count(word))
                        {
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    word[i] = og;
                }
            }
        }
        return 0;
    }
};
