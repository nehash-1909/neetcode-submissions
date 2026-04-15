class Solution {
public:
    int lip(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp, int prevVal)
    {
        if(i<0 || j<0 || i>= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= prevVal)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        dp[i][j] = max({1,1+lip(matrix, i+1, j, dp,matrix[i][j]), 1+lip(matrix, i-1, j, dp,matrix[i][j]), 1+lip(matrix, i, j+1, dp,matrix[i][j]), 1+lip(matrix, i, j-1, dp,matrix[i][j])});
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        int res = -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res = max(res, lip(matrix, i, j, dp,-1));
            }
        }
        return res;
        
    }
};
