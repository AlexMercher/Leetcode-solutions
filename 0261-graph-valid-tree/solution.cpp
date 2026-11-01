class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
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
        return tot==n;
    }
};
