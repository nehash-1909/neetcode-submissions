class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pair<int,int>>> maxHeap;
        //vector<vector<int>> res;
        for(auto point: points)
        {
            int x = point[0];
            int y = point[1];

            int dis = x*x + y*y;
            
            maxHeap.push({dis,{x,y}});
            if(maxHeap.size() > k)
                maxHeap.pop(); 

        } 

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
        
    }
};
