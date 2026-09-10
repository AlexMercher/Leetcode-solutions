class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0, twenty=0;
        for(int x:bills){
            if(x==5) five++;
            else if(x==10 && five>0){
                ten++;
                five--;
            }
            else if(x==20){
                twenty++;
                if(ten>=1 && five>=1){
                    five--;
                    ten--;
                }else if(five>=3) five-=3;
                else return false;
            }
            else return false;
        }
        return true;
    }
};