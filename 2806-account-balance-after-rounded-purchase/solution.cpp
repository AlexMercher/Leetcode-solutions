class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int unit=purchaseAmount%10;
        int rounded=0;
        if(unit>=5){
            rounded=purchaseAmount+(10-unit);
        }else{
            rounded=purchaseAmount-(unit);
        }
        return 100-rounded;
    }
};