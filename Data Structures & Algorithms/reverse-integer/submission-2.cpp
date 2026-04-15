class Solution {
public:
    int reverse(int x) {

        long long i = 0;
        long long max = (1<<31)-1;
        long long min = (-(1<<31));
        //long long x = (long long)y;
        //cout<<min<<" "<<max<<endl;
        int count = 0;
        while(x)
        {
            int rem = x%10;
            x = x/10;
            i = i*10 + rem;
            count++;
        }
        if(i >= max || i <= min)
            return 0;
        return (int)i;
        
    }
};
