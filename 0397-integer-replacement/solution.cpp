class Solution {
public:
    int integerReplacement(int n) {
        int count=0;
        long long x=n;
        while(x!=1){
            if(x%2==0)
                x/=2;
            else if((x&2)==0 || x==3) x--;
            else x++;
            count++;
        }
        return count;
    }
};