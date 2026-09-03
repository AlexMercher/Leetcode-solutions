class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> maxLen(26,0);
        int len=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(i>0 && (s[i]-s[i-1]+26)%26==1) len++;
            else len=1;
            maxLen[idx]=max(maxLen[idx],len);
        }
        int ans=0;
        for(int x:maxLen) ans+=x;
        return ans;
    }
};