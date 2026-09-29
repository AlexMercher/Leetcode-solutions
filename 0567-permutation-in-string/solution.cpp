class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        int k=s1.size();
        vector<int> need(26,0);
        vector<int> window(26,0);
        for(char c:s1){
            need[c-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            window[s2[i]-'a']++;
            if(i>=k){
                window[s2[i-k]-'a']--;
            }
            if(window==need) return true;
        }
        return false;
    }
};