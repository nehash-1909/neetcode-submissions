class Solution {
public:
    double helper(double x, long n) 
    {
        if(n == 0)
            return 1;


        double half = helper(x,n/2);
        if(n%2)
            return x*half*half;
        return half*half;
        
    }
    double myPow(double x, int n) 
    {
        if(x==0)
            return 0;
        double res = helper(x,n);
        if(n<0)
            return 1/res;
        return res;
        
    }
};
