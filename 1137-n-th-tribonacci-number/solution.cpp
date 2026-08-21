class Solution {
public:
    int tribonacci(int n) {
        int T_0=0;int T_1=1; int T_2=1;
        int T_3=0;
        for(int i=3;i<=n;i++){
            T_3=T_0+T_2+T_1;
            int temp=T_2;
            T_2=T_3;
            T_0=T_1;
            T_1=temp;
        }
        return (n>=3)?T_3:(n>=1)?1:0;
    }
};