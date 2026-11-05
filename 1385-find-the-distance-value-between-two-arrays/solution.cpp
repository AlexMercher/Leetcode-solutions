class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        for(int x:arr1){
            for(int x2:arr2){
                if(abs(x-x2)<=d){
                    goto end;
                }
            }
            count++;
            end:
        }
        return count;
    }
};