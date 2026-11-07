class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        using Server=tuple<long long,int,int>;//Freetime,weight,index;
        priority_queue<Server,vector<Server>,greater<Server>> busy;
        for(int i=0;i<n;i++){
            available.push({servers[i],i});
        }
        vector<int> ans(m);
        long long time=0;
        for(int i=0;i<m;i++){
            time=max(time,(long long)i);
            while(!busy.empty() && get<0>(busy.top())<=time){//While is used as many servers can get free at the same time.
                auto [freetime,weight,index]=busy.top();
                busy.pop();
                available.push({weight,index});
            }
            if(available.empty()){
                time=get<0>(busy.top());
                while(!busy.empty()&& get<0>(busy.top())<=time){
                    auto [freetime,weight,index]=busy.top();
                    busy.pop();
                    available.push({weight,index});
                }
            }//Now we have freed the servers that could be freed so that the available is now ready for taking new requests.
            auto [weight,index]=available.top();
            available.pop();
            ans[i]=index;
            busy.push({time+tasks[i],weight,index});//Push with the new endtime and then with the weight and the index of the server.
        }
        return ans;
    }
};