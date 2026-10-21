class Solution {
public:
    int minOperations(string s) {
        const int n=s.size();
        if(is_sorted(s.begin(),s.end())) return 0;
        char mn=s[0];
        char mx=s[0];
        for(int i=1;i<n;i++){
            mn=min(mn,s[i]);
            mx=max(mx,s[i]);
        }

        if(s[0]==mn || s[n-1]==mx) return 1;
        if(n==2) return -1;
        for(int i=1;i+1<n;i++){
            if(s[i]==mn || s[i]==mx) return 2;
        }
        return 3;
    }
};