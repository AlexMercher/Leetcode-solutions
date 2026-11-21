class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> children(n);
        for(int i=1;i<n;i++){
            children[parent[i]].push_back(i);
        }

        vector<int> newParent=parent;
        vector<int> last(26,-1);
        vector<int> previous(n,-1);
        vector<int> order;
        order.reserve(n);

        stack<pair<int,bool>> st;
        st.push({0,false});

        while(!st.empty()){
            auto [node,isExit]=st.top();
            st.pop();
            int c=s[node]-'a';

            if(isExit){
                last[c]=previous[node];
                continue;
            }
            order.push_back(node);

            previous[node]=last[c];
            if(last[c]!=-1){
                newParent[node]=last[c];
            }
            last[c]=node;
            st.push({node,true});
            for(int i=(int)children[node].size()-1;i>=0;i--){
                st.push({children[node][i],false});
            }
        }
        vector<int> ans(n,1);
        for(int i=n-1;i>0;i--){
            int node=order[i];
            ans[newParent[node]]+=ans[node];
        }
        return ans;
    }
};