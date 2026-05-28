class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        int sign = -1;
        int count = 0;
        int maxAns = 0;
        for(int i=0;i<n-1;i++)
        {
            // tracck sign is alternative
            if(arr[i] > arr[i+1])
            {
                count = (sign == 0)? count+1:1;
                sign = 1;
            }
            else if(arr[i] < arr[i+1])
            {
                count = (sign == 1)? count+1:1;
                sign = 0;
            }
            else
            {
                sign = -1;
                count = 0;
            }
            maxAns = max(maxAns, count);
        }

        return maxAns+1;

        
    }
};