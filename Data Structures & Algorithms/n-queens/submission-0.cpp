class Solution {
public:
    void getQueen(vector<vector<string>> &res, vector<string> &ans, int n, int row, set<int> &hashCol, set<int> &hashright, set<int> &hashleft)
    {
        if(row == n)
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(hashCol.contains(i))
                continue;

            if(hashright.contains(i+row))
                continue;
            
            if(hashleft.contains(i-row))
                continue;

            string p(n, '.');

            p[i] = 'Q';
            ans.push_back(p);
            hashCol.insert(i);
            hashright.insert(i+row);
            hashleft.insert(i-row);

            getQueen(res,ans,n,row+1,hashCol,hashright, hashleft);

            p[i] = '.';
            ans.pop_back();
            hashCol.erase(i);
            hashright.erase(i+row);
            hashleft.erase(i-row);
        }

        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ans;

        set<int> hashCol;
        set<int> hashright; 
        set<int> hashleft;

        getQueen(res,ans,n,0,hashCol,hashright, hashleft);

        return res;

        
    }
};
