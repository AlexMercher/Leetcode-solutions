class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int half=n/2;
        int leftsum=0,rightsum=0;
        int leftQ=0,rightQ=0;
        for(int i=0;i<half;i++){
            if(num[i]=='?') leftQ++;
            else leftsum+=num[i]-'0';
        }
        for(int i=half;i<n;i++){
            if(num[i]=='?') rightQ++;
            else rightsum+=num[i]-'0';
        }
        int totalQ=rightQ+leftQ;

        if(totalQ%2==1) return true;

        int diff=leftsum-rightsum;
        int qdiff=rightQ-leftQ;

        return diff != 9 * qdiff / 2;
    }
};