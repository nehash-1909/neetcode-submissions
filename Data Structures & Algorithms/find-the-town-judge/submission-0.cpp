class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {

        /*
            1 -> 3
            4 -> 3
            2 -> 3
        */

        int judge = trust[0][1];

        for(auto per: trust)
        {
            if(per[1] != judge)
                return -1;
            if(per[0] == judge)
                return -1;
        }

        return judge;


        
    }
};