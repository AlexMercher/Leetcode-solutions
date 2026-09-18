class Solution {
public:
    int solve(int n,int s){
        string ans="";
        for(int i=0;i<n;i++){
            int x=min(9,s);
            ans+=char('0'+x);
            s-=x;
        }
        return stoi(ans);
    }
    int largestInteger(int n, int s) {
        if(9*n<s) return -1;
        else if(s==0) return 0;
        else return solve(n,s);
    }
};