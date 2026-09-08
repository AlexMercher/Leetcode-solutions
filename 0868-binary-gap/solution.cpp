class Solution {
public:
    int binaryGap(int n) {
        if((n&(n-1))==0) return 0;
        int prev=-1;
        int pos=0;
        int best=0;
        while(n>0){
            if(n&1){
                if(prev!=-1){
                    best=max(best,pos-prev);
                }
                prev=pos;
            } 
            n>>=1;
            pos++;
        }
        return best;
    }
};