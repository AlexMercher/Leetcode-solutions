class Solution {
public:
    int reverseDegree(string s) {
        vector<int> freq(26);
        for(int i=0;i<26;i++){
            freq[i]=26-i;
        }
        int rev_deg=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            rev_deg+=freq[s[i]-'a']*(i+1);
        }
        return rev_deg;
    }
};