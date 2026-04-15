class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //vector<int> ans;
        set<int> s;
        int minE = INT_MAX;
        int maxE = INT_MIN;
        for(auto i:nums)
        {
            s.insert(i);
            minE = min(minE, i);
            maxE = max(maxE, i);
        }
        int counter = 0;
        //int start;
        //int end;
        for(int i = minE; i<=maxE; i++)
        {
            int temp = 0;
            //int temps = i;
            while(i<=maxE && s.contains(i))
            {
                temp++;
                i++;
            }
            counter = max(counter,temp);

        }

        

        return counter;
        
    }
};
