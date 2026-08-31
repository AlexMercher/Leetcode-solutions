class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int ans=10,choices=9,available=9;
        for(int i=2;i<=n;i++){
            choices*=available;
            ans+=choices;
            available--;
        }
        return ans;
    }
};