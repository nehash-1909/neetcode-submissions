class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int ans = 0;
        int fuel = 0;
        int costGas = std::accumulate(gas.begin(), gas.end(), 0);
        int costFuel = std::accumulate(cost.begin(), cost.end(), 0);
        if(costFuel > costGas)
            return -1;
        for(int i=0;i<n;i++)
        {
            fuel += (gas[i] - cost[i]); 

            if(fuel < 0)
            {
                ans = i+1;
                fuel = 0;
            }
        }

        return ans;
        
    }
};
