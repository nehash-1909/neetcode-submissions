#include <string>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {

        string s = "";

        for(int i=0;i<digits.size();i++)
        {
            s += (digits[i]+'0');
        }

        long long number = stoll(s);
        number++;

        vector<int> res;
        // 1 2 3 5
        long long i=0;
        while(number>0)
        {
            res.insert(res.begin(),number%10);
            number = number/10;
        }

        return res;
        
    }
};
