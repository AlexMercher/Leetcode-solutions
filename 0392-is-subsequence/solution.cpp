class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();
        int index=0;
        for(int i=0;i<n && index<m;i++){
            if(t[i]==s[index]){
                index++;
            }
        }
        return index==m;
    }
};