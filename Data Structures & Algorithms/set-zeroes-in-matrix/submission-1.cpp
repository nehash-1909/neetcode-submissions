class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


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
        #if 0
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = -1;
                    matrix[0][j] = -1;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            if(matrix[i][0] == -1)
            {
                for(int j=1;j<m;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1;j<n;j++)
        {
            if(matrix[j][0] == -1)
            {
                for(int i=1;i<m;i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=0;j<m;j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i=0;i<n;i++)
                {
                    matrix[i][j] = 0;
                }
            } 
        }

        for(int j=0;j<m;j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i=0;i<m;i++)
                {
                    matrix[0][j] = 0;
                }
                break;
            } 
        }
        #endif

        // 1 2 0 4    1 -1 0 4    1 -1 0 4.    1 -1 0 4
        // 5 0 7 8 => -1 0 7 8.  -1  0 7 8.    -1 0 0 0
        // 1 2 3 4.    1 2 3 4    1  0 3 4.     1 0 0 4
        // 5 6 7 8.    5 6 7 8    5  0 7 8.     5 0 0 8


    }
};
