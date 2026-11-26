class Solution {
public:
    bool canAliceWin(int n) {
        int remove=10;
        bool alice=false;
        while(n>=remove){
            n-=remove;
            remove--;
            alice=!alice;
        }
        return alice;
    }
};