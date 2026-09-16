class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=i;
        }
        int i=0;
        while(i<n){
            if(s[i]=='D'){
                int j=i;
                while(j<n && s[j]=='D') j++;
                reverse(ans.begin()+i,ans.begin()+j+1);

                i=j;
            }
            else i++;
        }
        return ans;
    }
};