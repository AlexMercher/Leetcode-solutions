class Solution {
public:
    int countEven(int num) {
        int sum=0;
        for(int x=num;x>0;x/=10){
            sum+=x%10;
        }
        return (num-sum%2)/2;
    }
};