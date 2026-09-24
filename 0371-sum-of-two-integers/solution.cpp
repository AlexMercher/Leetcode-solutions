class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned int carry=((unsigned int)a&(unsigned int)b)<<1;//If both bits are 1 then we carry hence the << feature is there;
            a=a^b;
            b=(int)carry;
        }
        return a;
    }
};