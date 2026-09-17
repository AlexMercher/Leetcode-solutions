class Solution {
public:
    int convert(string s){
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3,2));
        return h*60+m;
    }
    int convertTime(string current, string correct) {
        int curr=convert(current);
        int corr=convert(correct);

        int diff=corr-curr;
        int ans=0;
        ans+=diff/60;
        diff%=60;

        ans+=diff/15;
        diff%=15;

        ans+=diff/5;
        diff%=5;
        ans+=diff;
        return ans;
    }
};