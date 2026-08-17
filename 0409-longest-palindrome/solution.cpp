class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        int n=s.size();
        vector<int> freq(256,0);
        for(char c:s){
            freq[c]++;
        }
        int isOdd=false;
        int ans=0;
        for(int x:freq){
            ans+=x/2;
            if(x%2==1) isOdd=true;
        }
        if(isOdd) return ans*2+1;
        return ans*2;
    }
};