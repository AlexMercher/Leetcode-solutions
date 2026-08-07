class Solution {
public:
    int reverse(int x) {
        int reverse=0;
        reverse=Digit(x);
        return reverse;
    }
    int Digit(int x){
        int reverse=0;
        while(x!=0){
            int digit=x%10;
            if(reverse>INT_MAX/10) return 0;
            else if(reverse==INT_MAX/10&&digit>7) return 0;
            else if(reverse<INT_MIN/10||(reverse==INT_MIN/10 && digit<-8)) return 0;
            reverse=reverse*10+digit;
            x=x/10;
        }
        return reverse;
    }
};