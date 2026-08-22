class Solution {
public:
    bool checkDivisibility(int n) {
        int sum_together=getsum(n);
        return n%sum_together==0;
    }
    int getsum(int n){
        int sum=0;
        int product=1;
        while(n!=0){
            int digit=n%10;
            sum+=digit;
            product*=digit;
            n=n/10;
        }
        return sum+product;
    }
};