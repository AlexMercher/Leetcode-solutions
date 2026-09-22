class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans=prices;
        int n=prices.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&prices[st.top()]>=prices[i]){
                int j=st.top();
                st.pop();
                ans[j]-=prices[i];
            }
            st.push(i);
        }
        return ans;
    }
};