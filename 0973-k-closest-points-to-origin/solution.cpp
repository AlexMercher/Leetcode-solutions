class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> q;
        for(vector<int> point:points){
            int x=point[0];
            int y=point[1];
            int dist=x*x + y*y;
            q.push({dist,{x,y}});
            if(q.size()>k) q.pop();
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            ans.push_back({q.top().second.first,q.top().second.second});
            q.pop();
        }
        return ans;
    }
};