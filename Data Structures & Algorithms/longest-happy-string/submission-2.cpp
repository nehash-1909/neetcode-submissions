class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        string s = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while(!pq.empty())
        {
            auto [frq, ele] = pq.top();
            pq.pop();
            // already have 2 elements 
            int m = s.size();
            if(m >= 2 && s[m-1] == ele && s[m-2] == ele)
            {
                // if heap is empty
                if(pq.empty())
                    return s;

                auto [frq2, ele2] = pq.top();
                pq.pop();

                s += ele2;
                // we can add one more
                if(frq2 > 1)
                {
                    //s += ele2;
                    pq.push({frq2-1, ele2});
                }
                pq.push({frq,ele});

            }
            else
            {
                s += ele;
                if(frq > 1)
                    pq.push({frq-1,ele});
            }

        }
        return s;        
    }
};