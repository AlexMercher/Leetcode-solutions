class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int x=left;x<=right;x++){
            int co=__builtin_popcount(x);
            if(co==2 || co ==3 || co ==5|| co==7|| co ==11 || co==13
            || co ==17|| co == 19) count++;
        }
        return count;
    }
};