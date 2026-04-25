class CountSquares {
public:
    map<vector<int>,int> points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point]++;
    }
    int count(vector<int> point) 
    {

        
        /*
                (2,0)       (2,2)


                (0,0)       (0,2)
        */
        int res = 0;
        for(auto const& [p, freq] : points)
        {
            //check if we have diagonal
            if(abs(point[0]-p[0]) != abs(point[1]-p[1]) || (point[0]==p[0]) || (point[1] == p[1]))
                continue;
            // get two other points
            vector<int> p1 = {point[0], p[1]};
            vector<int> p2 = {p[0], point[1]};
            if (points.count(p1) && points.count(p2)) {
                res += freq * points[p1] * points[p2];
            }
        }

        return res;
        
    }
};