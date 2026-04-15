class Solution {
public:
    int reverse(int y) {

        // long long i = 0;
        long long max = (1LL << 31) - 1;
        long long min = (-(1LL << 31));
        //long long x = (long long)y;
        //cout<<min<<" "<<max<<endl;

        string s = to_string(llabs(y));
        std::reverse(s.begin(), s.end());
        long long x = stoll(s);
        if(y < 0)
            x = x*-1;
        // int count = 0;
        // while(x)
        // {
        //     int rem = x%10;
        //     x = x/10;
        //     i = i*10 + rem;
        //     count++;
        // }
        if(x > max || x < min)
            return 0;
        return (int)x;
        
    }
};
