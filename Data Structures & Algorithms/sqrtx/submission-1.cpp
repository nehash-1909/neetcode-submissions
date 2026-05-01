class Solution {
public:
    int mySqrt(int x) 
    {

        int l = 0;
        int r = x;

        while(l<=r)
        {
            int m = l + (r - l) / 2;
            long long num = 1LL *m*m;
            if((long long)num == x)
                return m;
            else if((long long)num > x)
                r = m-1;
            else
                l = m+1;
        }
        return r;
        
        
    }
};