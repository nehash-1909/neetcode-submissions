class Solution {
public:
    string reorganizeString(string s) 
    {
        int n = s.size();

        string ans = "";
        unordered_map<char,int> frq;

        for(auto c:s)
        {
            frq[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &p : frq)
            pq.push({p.second, p.first});

        while(pq.size()>=2)
        {
            auto [max1_frq, max1_ele] = pq.top();
            pq.pop();

            auto [max2_frq, max2_ele] = pq.top();
            pq.pop();

            ans += max1_ele;
            ans += max2_ele;

            if(max1_frq > 1)
                pq.push({max1_frq-1, max1_ele});
            
            if(max2_frq > 1)
                pq.push({max2_frq-1, max2_ele});

        }

        if(!pq.empty())
        {

            auto [last_frq, last_ele] = pq.top();
            pq.pop();

            if(last_frq > 1)
                return "";
            
            ans += last_ele;

        }

        return ans;
              
              
        
        
    }
};