class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for(int i=0;i<k;i++){
            available.insert(i);
        }
        priority_queue<pair<long long,int>,
                        vector<pair<long long,int>>,
                        greater<pair<long long,int>>> busy;
        
        vector<int> count(k,0);
        int maxCount=0;
        int n=arrival.size();
        for(int i=0;i<n;i++){
            while(!busy.empty() && busy.top().first<=arrival[i]){
                auto [finishtime,server]=busy.top();
                busy.pop();

                available.insert(server);
            }
            if(available.empty()) continue;//If no servers are available drop it.

            int start=i%k;
            auto it=available.lower_bound(start);
            if(it==available.end()) it=available.begin();
            int server=*it;
            available.erase(it);
            count[server]++;
            maxCount=max(maxCount,count[server]);
            
            long long finishTime=(long long)arrival[i]+load[i];
            busy.push({finishTime,server});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(count[i]==maxCount) ans.push_back(i);
        }
        return ans;
    }
};