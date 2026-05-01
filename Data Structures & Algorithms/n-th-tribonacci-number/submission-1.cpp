class Solution {
public:
    int tribonacci(int n) 
    {
        

        int f = 0;
        int s = 1;
        int t = 1;
        int sum = f+s+t;
        if(n == 0 || n==1)
            return n;
        if(n == 2)
            return 1;
        if(n <= 3)
            return sum;

        for(int i=4;i<=n;i++)
        {
            //cout<<i;
            f = s;
            s = t;
            t = sum;
            sum = (f+s+t);
        }

        return sum;
        
    }
};