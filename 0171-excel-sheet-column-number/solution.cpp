class Solution {
public:
    int titleToNumber(string columnTitle) {
        int value=0;
        int n=columnTitle.size();
        for(int i=0;i<n;i++){
            int val=columnTitle[i]-'A'+1;
            value=value*26+val;
        }
        return value;
    }
};