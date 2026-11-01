class Solution {
public:
    void find(queue<int>& q,vector<bool>& visited){
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                return;
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0]=true;
        int tot=0;
        int count=0;
        while(tot!=n){
            while(!q.empty()){
                int node=q.front();
                q.pop();
                tot++;
                for(int n:adj[node]){
                    if(!visited[n]){
                        q.push(n);
                        visited[n]=true;
                    }
                }
            }
            count++;
            find(q,visited);
        }
        return count;
    }
};
