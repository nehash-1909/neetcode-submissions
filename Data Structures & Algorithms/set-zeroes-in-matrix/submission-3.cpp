class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool isFirstRow = false;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if(i == 0)
                        isFirstRow = true;
                    else
                        matrix[i][0] = 0;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0)
        {
            for(int j=0;j<n;j++)
            {
                matrix[j][0] = 0;
            }
        }
        if(isFirstRow)
        {
            for(int j=0;j<m;j++)
            {
                matrix[0][j] = 0;
            }
        }

    }
    #if 0
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>> mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    mat.push_back({i,j});
                }
            }
        }
        for(auto [row,column]:mat)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][column] = 0;
            }
            for(int i=0;i<m;i++)
            {
                matrix[row][i] = 0;
            }
        }
    }
    #endif
};
