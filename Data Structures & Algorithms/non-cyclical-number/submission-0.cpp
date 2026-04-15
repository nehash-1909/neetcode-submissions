class Solution {
public:
    bool isHappy(int n) {
        set<int> s;

        while(n!=1)
        {
            if(s.contains(n))
                return false;
            s.insert(n);
            int temp = n;
            n = 0;
            while(temp)
            {
                int rem = temp%10;
                rem = rem*rem;
                n +=rem;
                temp = temp/10;
            }
        }

        return true;
        
    }
};
