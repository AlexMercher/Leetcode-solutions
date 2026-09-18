class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> q;
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(auto x:adj[node]){
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return false;
    }
};