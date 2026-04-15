class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        //increasing --> sorted
        // 1 2 10 14 19 25
        // dup
        vector<int> res(2,0);
        int l = 0;
        int r = numbers.size()-1;

        while(l<r)
        {
            if(numbers[l]+numbers[r] > target)
                r--;
            else if(numbers[l]+numbers[r] < target)
                l++;
            else
            {
                cout<<numbers[l]<<" "<<numbers[r]<<endl;
                res[0] = l+1;
                res[1] = r+1;
                return res;
            }
        } 
        
        return res;
    }
};
