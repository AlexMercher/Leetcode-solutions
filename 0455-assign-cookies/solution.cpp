class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        int m=g.size();
        sort(s.begin(),s.end());
        int n=s.size();
        int j=0;
        int count=0;
        for(int i=0;i<m;i++){
            while(j<n && g[i]>s[j]) j++;
            if(j==n) break;
            count++;
            j++;
        }
        return count;
    }
};