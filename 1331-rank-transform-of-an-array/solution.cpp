class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        int n=arr.size();
        vector<int> ans(arr.size(),0);
        unordered_map<int,int> rank;
        int r=0;
        for(int x:sorted){
            if(rank.find(x)==rank.end()){
                rank[x]=++r;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=rank[arr[i]];
        }
        return ans;
    }
};