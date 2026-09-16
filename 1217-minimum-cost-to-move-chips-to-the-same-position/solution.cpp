class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int nodds=0;
        int nevens=0;
        for(int x:position){
            if(x&1) nodds++;
            else nevens++;
        }
        if(nevens>nodds){
            return nodds;
        }
        else return nevens;
    }
};