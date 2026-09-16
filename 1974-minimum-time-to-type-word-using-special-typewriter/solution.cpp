class Solution {
public:
    int minTimeToType(string word) {
        int ans=0;
        int curr='a';
        for(char c:word){
            int diff=abs(c-curr);
            ans+=min(diff,26-diff)+1;
            curr=c;
        }
        return ans;
    }
};