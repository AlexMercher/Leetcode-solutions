class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int total_cost=0;
        int count=0;
        for(int i=n-1;i>=0;i--){
            count++;
            if(count%3==0){
                count=0;
                continue;
            }
            total_cost+=cost[i];
        }
        return total_cost;
    }
};