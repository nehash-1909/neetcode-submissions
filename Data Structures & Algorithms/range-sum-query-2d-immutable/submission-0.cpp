class NumMatrix {
public:
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sumMatrix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                sumMatrix[i][j] = sumMatrix[i-1][j] + sumMatrix[i][j-1] + matrix[i-1][j-1] - sumMatrix[i-1][j-1];;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        row1++; col1++; row2++; col2++;
        int ans = sumMatrix[row2][col2] - sumMatrix[row1-1][col2] - sumMatrix[row2][col1-1] + sumMatrix[row1-1][col1-1]; 
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */