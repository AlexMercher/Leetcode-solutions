class Solution {
public:
    int countbits(int n){
        int count=0;
        while(n>0){
            count+=(n&1);
            n>>=1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int hour=0;hour<12;hour++){
            for(int min=0;min<60;min++){
                if(countbits(hour)+countbits(min)!=turnedOn) continue;
                string time=to_string(hour)+":";
                if(min<10) time+="0";
                time+=to_string(min);
                ans.push_back(time);
            }
        }
        return ans;
    }
};