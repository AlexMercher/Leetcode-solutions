class Solution {
    struct Fenwick{
        int n;
        vector<int> bit;
        Fenwick(int n): n(n), bit(n+1,0) {}

        void add(int i,int x){
            for(; i<=n;i+=i&-i) bit[i]^=x;
        }

        int query(int i){
            int ans=0;
            for(;i>0; i-=i&-i) ans^=bit[i];
            return ans;
        }
        //Xor update of the inclusive range [l,r] using 0 based indices.
        void rangeXor(int l,int r,int x){
            add(l+1,x);
            if(r+2<=n) add(r+2,x);
        }
    };

    vector<vector<int>> adj,up;
    vector<int> depth,tin,tout,base;
    string s;
    int LOG,timer;

    void dfs(int u,int p){
        tin[u]=timer++;
        up[0][u]=p;

        base[u]=(p==u? 0 : base[p])^ (1<<(s[u]-'a'));
        for(int j=1;j<LOG;j++){
            up[j][u]=up[j-1][up[j-1][u]];
        }

        for(int v:adj[u]){
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
        tout[u]=timer-1;
    }
    int lca(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);
        int diff=depth[u]-depth[v];

        for(int j=0;j<LOG;j++){
            if(diff&(1<<j)) u=up[j][u];
        }
        if(u==v) return u;
        for(int j=LOG-1;j>=0;j--){
            if(up[j][u] != up[j][v]){
                u=up[j][u];
                v=up[j][v];
            }
        }
        return up[0][u];
    }
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string str, vector<string>& queries) {
        s=str;
        adj.assign(n,{});
        depth.assign(n,0);
        tin.assign(n,0);
        tout.assign(n,0);
        base.assign(n,0);

        LOG=1;
        while((1<<LOG)<=n) LOG++;
        up.assign(LOG,vector<int> (n,0));
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        timer=0;
        dfs(0,0);

        Fenwick fw(n);
        vector<bool> ans;

        auto prefixmask=[&](int u){
            return base[u]^fw.query(tin[u]+1);
        };
        for(string& q:queries){
            string op;
            int u,v;
            char c;

            stringstream ss(q);
            ss>>op>> u;
            if(op=="update"){
                ss>>c;
                int delta=(1<<(s[u]-'a'))^(1<< (c-'a'));
                fw.rangeXor(tin[u],tout[u],delta);
                s[u]=c;
            }else{
                ss>>v;
                int w=lca(u,v);
                int mask=prefixmask(u)^prefixmask(v)^(1<<(s[w]-'a'));
                ans.push_back(__builtin_popcount((unsigned)mask)<=1);
            }
        }
    return ans;
    }
};