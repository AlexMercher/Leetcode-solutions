class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int dual=0;
        int single=0;
        for(int x:nums){
            if(x<10) single+=x;
            else dual+=x;
        }
        
        return !(single==dual);
    }
};