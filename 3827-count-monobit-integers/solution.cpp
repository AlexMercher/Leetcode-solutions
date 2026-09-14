class Solution {
public:
    int build(int n){
        int ans=1;
        int count=0;
        while(ans<=n){
            ans=ans<<1 |1;
            count++;
        }
        return count;
    }
    int countMonobit(int n) {
        return 1+build(n);
    }
};