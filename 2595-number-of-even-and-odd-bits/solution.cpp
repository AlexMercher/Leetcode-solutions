class Solution {
public:
    vector<int> evenOddBit(int n) {
        int count=0;
        int even=0;
        int odd=0;
        while(n>0){
            if(n&1){
                if(count %2==0) even++;
                else odd++;
            }
            count++;
            n=n>>1;
        }
        return {even,odd};
    }
};