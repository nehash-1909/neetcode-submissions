class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;

        int l =0;
        int r = heights.size()-1;

        while(l<r)
        {
            int width = r-l;
            int len = min(heights[l], heights[r]);

            int area = width*len;
            maxA = max(maxA,area);

            if(heights[l] > heights[r])
                r--;
            else
                l++;
        }

        return maxA;
        
    }
};
