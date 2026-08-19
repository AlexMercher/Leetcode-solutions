class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rows;
        for(auto& seat: reservedSeats){
            int row=seat[0];
            int s=seat[1];
            rows[row] |= (1<<s);
        }
        int ans=(n-rows.size())*2;
        int left=(1<<2)|(1<<3)|(1<<4)|(1<<5);
        int middle=(1<<4)|(1<<5)|(1<<6)|(1<<7);
        int right=(1<<6)|(1<<7)|(1<<8)|(1<<9);

        for(auto &[row,mask]:rows){
            bool canleft=(mask & left) == 0;
            bool canright=(mask & right)==0;
            if(canleft && canright) ans+=2;
            else if(canleft || canright) ans+=1;
            else if((mask & middle)==0) ans+=1;
        }
        return ans;
    }
};