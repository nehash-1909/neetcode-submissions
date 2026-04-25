class Twitter {
public:
    unordered_map<int, unordered_set<int>> followers; // user -> followers
    unordered_map<int, vector<pair<int,int>>> tweets; // user --> twists
    int time  = 0;
    Twitter() 
    {   
    }
    void postTweet(int userId, int tweetId) 
    {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> res;
        // ensure self-follow
        followers[userId].insert(userId);

        vector<pair<int,int>> unsorted_list;

        // single loop (no duplication)
        for(auto f : followers[userId])
        {
            for(auto &t : tweets[f])
                unsorted_list.push_back(t);
        }

        sort(unsorted_list.begin(), unsorted_list.end(), comp);
        int i = 0;
        for(auto &ele: unsorted_list)
        {
            //cout<<ele.second<<" ";
            if(i>=10)
                return res;
            i++;
            res.push_back(ele.second);
        }
        return res;        
    }
    
    void follow(int followerId, int followeeId) 
    {
        followers[followerId].insert(followeeId);   
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        followers[followerId].erase(followeeId);
        
    }
};
