class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=n*n;
        int sumeven=n*(n+1);
        return GCD(sumodd,sumeven);
    }
    int GCD(int num1,int num2){
        if(num2==0) return num1;
        return GCD(num2,num1%num2);
    }
};