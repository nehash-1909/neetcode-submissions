class Solution {
public:
    int getRow(vector<vector<int>>& matrix, int target)
    {
        int l = 0;
        int r = matrix.size()-1;
        int n = matrix[0].size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            //cout<<l<<" "<<m<<" "<<r<<endl;
            if(matrix[m][0] <= target && matrix[m][n] >= target)
            {
                //cout<<"returning m: "<<m<<endl;
                return m;
            }
            else if(matrix[m][0] > target)
            {
                
                r = m-1;
                //cout<<"else if: "<<r<<endl;
            }
            else
            {
                
                l = m+1;
                //cout<<"else : "<<l<<endl;
            }
        }
        //cout<<"returning : "<<endl;
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = getRow(matrix, target);
        cout<<row<<endl;
        if(row == -1)
            return false;
        //#if 0 
        int l = 0;
        int r = matrix[0].size()-1;

        while(l<=r)
        {
            int m = (l+r)/2;

            if(matrix[row][m] == target)
                return true;

            else if(matrix[row][m] > target)
                r = m-1;
            else
                l = m+1;
        }
        //#endif
        return false;
    }
};
