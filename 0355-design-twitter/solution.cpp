class Twitter {
public:
    int timer=0;
    vector<unordered_set<int>> following;
    vector<vector<pair<int,int>>> tweets;
    Twitter() {
        following.resize(501);
        tweets.resize(501);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<tuple<int,int,int>> pq;
        if(!tweets[userId].empty()){
            int idx=tweets[userId].size()-1;
            pq.push({
                tweets[userId][idx].first,
                userId,idx
            });
        }

        for(int followee:following[userId]){
            if(!tweets[followee].empty()){
                int idx=tweets[followee].size()-1;
                pq.push({
                    tweets[followee][idx].first,
                    followee, idx
                });
            }
        }
        while(!pq.empty() && ans.size()<10){
            auto[time,user,idx]=pq.top();
            pq.pop();

            ans.push_back(tweets[user][idx].second);
            if(idx>0){
                int nextidx=idx-1;
                pq.push({
                    tweets[user][nextidx].first, user, nextidx
                });
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */