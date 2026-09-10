class Solution {
public:
    int xorOperation(int n, int start) {
        int xo=0;
        for(int i=0;i<n;i++){
            xo^=(start+2*i);
        }
        return xo;
    }
};