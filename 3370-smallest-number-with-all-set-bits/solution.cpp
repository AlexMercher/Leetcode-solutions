class Solution {
public:
    int build(int n){
        int ans=1;
        if(ans>=n) return ans;
        while(true){
            ans=ans<<1 | 1;
            if(ans>=n) break;
        }
        return ans;
    }
    int smallestNumber(int n) {
        return build(n);
    }
};