class Solution {
public:
    char kthCharacter(int k) {
        int shifts=0;
        k--;
        while(k>0){
            shifts+=k&1;
            k>>=1;
        }
        return 'a'+shifts;
    }
};