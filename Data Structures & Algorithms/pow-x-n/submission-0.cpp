class Solution {
public:
    double myPow(double x, int n) 
    {
        double res = 1.0;
        //double x_pos = abs(x);
        for(int i=1;i<=abs(n);i++)
        {
            res = res*x;
        }
        if(n<0)
            return 1/res;
        return res;
        
    }
};
