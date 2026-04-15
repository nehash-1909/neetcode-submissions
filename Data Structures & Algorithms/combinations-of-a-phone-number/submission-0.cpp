class Solution {
public:
    void generate(string &digits,int i, string &ans,vector<string> &res,unordered_map<char,string> &hash)
    {
        if(ans.size() == digits.size())
        {
            res.push_back(ans);
            return;
        }

        if(hash.contains(digits[i]) == false)
            return;

        for(auto c: hash[digits[i]])
        {
            ans += c;
            //cout<<c<<" ";
            generate(digits, i+1, ans, res, hash);
            ans.pop_back();
            //cout<<endl;
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
            return {};
        unordered_map<char,string> hash = {{'1',""}, {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"},{'9',"wxyz"}};
        vector<string> res;
        string ans ="";
        generate(digits, 0, ans, res, hash);

        return res;

        
    }
};
