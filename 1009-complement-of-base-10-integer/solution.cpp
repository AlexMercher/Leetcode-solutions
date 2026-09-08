class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask=0;
        int dup=n;
        while(dup>0){
            mask=mask<<1 | 1;
            dup>>=1;
        }
        return mask&(~n);
    }
};