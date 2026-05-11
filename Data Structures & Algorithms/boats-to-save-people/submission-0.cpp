class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {

        sort(people.begin(), people.end());

        int l = 0;
        int r = people.size()-1;
        int ans = 0;

        while(l<=r)
        {
            // 1 2 2 3 3
            if(people[l] + people[r] <= limit)
            {
                l++;
            }
            r--;
            ans++;
        }

        return ans;
        
    }
};