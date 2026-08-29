class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        vector<int> hold(n,0);
        vector<int> free(n,0);
        hold[1]=max(-prices[0],-prices[1]);
        free[1]=max(0,prices[1]-prices[0]);

        for(int i=2;i<n;i++){
            hold[i]=max(hold[i-1],free[i-2]-prices[i]);
            free[i]=max(free[i-1],hold[i-1]+prices[i]);
        }
        return free[n-1];
    }
};