class Solution {
public:
    bool consecutiveSetBits(int n) {
        if(n<=2) return false;
        int count=0;
        while((n>>1)!=0){
            if((n&1) && ((n>>1)&1)) count++;
            if(count>=2) return false;
            n=n>>1;
        }
        return count==1;
    }
};