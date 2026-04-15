class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ans = 0;
        int n = height.size()-1;

        int maxL = height[0];
        int maxR = height[n];
        int l = 0;
        int r = n;
        while(l<=r)
        {
            if(maxL <= maxR)
            {
                int temp = (maxL - height[l]);
                if(temp > 0)
                    ans += temp;
                maxL = max(maxL, height[l]);
                l++;
            }
            else
            {
                int temp = (maxR - height[r]);
                if(temp > 0)
                    ans += temp;
                maxR = max(maxR, height[r]);
                r--;
            }
        }
        return ans;
    }
};
    #if 0
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size()-1;
        
        if(n == 0)
            return ans;
        
        vector<int> rightMax(n+1,0);
        rightMax[n] = height[n];

        for(int i=n-1;i>=0;i--)
        {
            rightMax[i] = max(height[i], rightMax[i+1]); 
        }

        int maxLeft = height[0];
        for(int i = 1; i<=n ; i++)
        {
            maxLeft = max(maxLeft, height[i]);
            ans += (min(maxLeft, rightMax[i])-height[i]);
            //cout<<ans<<endl;
        }

        return ans;
    }
    #endif

