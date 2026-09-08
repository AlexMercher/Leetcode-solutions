class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        int dup=num;
        while(dup>0){
            mask=mask<<1 | 1;
            dup>>=1;
        }
        return ~num & mask;
    }
};