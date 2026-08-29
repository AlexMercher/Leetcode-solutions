class Solution {
public:
    vector<int> parent,sz;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        parent.resize(n);
        sz.assign(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end());

        for(int i=1;i<n;i++){
            if((long long)a[i].first-a[i-1].first<=limit)
                unite(a[i].second,a[i-1].second);
        }
        unordered_map<int, vector<int>> indices;
        unordered_map<int, vector<int>> values;

        for(int i=0;i<n;i++){
            int root=find(i);
            indices[root].push_back(i);
            values[root].push_back(nums[i]);
        }
        vector<int> ans=nums;
        
        for(auto& [root,idx]:indices){
            auto& val=values[root];
            sort(idx.begin(),idx.end());
            sort(val.begin(),val.end());

            for(int i=0;i<idx.size();i++){
                ans[idx[i]]=val[i];
            }
        }
        return ans;
    }
};