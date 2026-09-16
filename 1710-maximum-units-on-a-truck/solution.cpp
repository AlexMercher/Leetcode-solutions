class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){
            return a[1]>b[1];
        });
        int n=boxTypes.size();
        int val=0;
        for(int i=0;i<n;i++){
            if(truckSize>=boxTypes[i][0]){ 
                val+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                int partial=truckSize;
                val+=boxTypes[i][1]*partial;
                truckSize-=partial;
            }
            if(truckSize==0) break;
        }
        return val;
    }
};